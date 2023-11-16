#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include "CComic.h"

using namespace std;

template <class T>
class CGrafo {
private:
	T vacio = nullptr;
	class CArco {
	public:
		T info; // info del arco
		int v;  // indice del vertice
		CArco(T info, int vLlegada) {
			this->info = info;
			v = vLlegada; // vertice a donde llegara
		}
		~CArco() {}
	};

public:
	class CVertice {
	public:
		T info;                       // informacion del vertice
		vector<CArco*>* ady;         // lista de adyacencia de class CArco, puntero vector
		unordered_map<string, vector<string>> genreGraph; // map para almacenar cómics relacionados por género

		CVertice(T info) {
			this->info = info;
			ady = new vector<CArco*>();
		}
		string toString() {
			stringstream ss;
			ss << "Vertice: " << this << " -> ";
			for (CArco* arco : *ady) {
				ss << arco->v << ", ";
			}
			return ss.str();
		}
	};

	vector<CVertice*>* vertices; // creamos vector de tipo entero
	CGrafo() { // Constructor del grafo
		vertices = new vector<CVertice*>();
	}

	~CGrafo() {
		for (typename vector<CVertice*>::iterator it = vertices->begin(); it != vertices->end(); ++it) {
			// Eliminar todas las aristas
			for (typename vector<CArco*>::iterator jt = (*it)->ady->begin(); jt != (*it)->ady->end(); ++jt) {
				delete* jt;
			}
			delete (*it)->ady;
			// Eliminar el vértice
			delete (*it)->info; // Liberar el puntero 'info'
			delete* it;
		}
		// Finalmente, eliminar el vector de vértices
		delete vertices;
	}

	void adicionarVertice(T info) {
		CVertice* vert = new CVertice(info); // Pasar 'info' al constructor de 'CVertice'
		vertices->push_back(vert);
	}
	void adicionarVerticeComic(CComic* comic) {
		CVertice* vert = new CVertice(comic);
		vertices->push_back(vert);

		// Conectar el nuevo cómic con todos los otros cómics del mismo género
		for (int i = 0; i < vertices->size() - 1; ++i) {
			CVertice* otherVert = vertices->at(i);
			if (otherVert->info->getGenre() == comic->getGenre()) {
				adicionarArco(i, vertices->size() - 1);

				// Actualizar el mapa de género
				const string& genre = comic->getGenre();
				vert->genreGraph[genre].push_back(otherVert->info->getTitle());
				otherVert->genreGraph[genre].push_back(comic->getTitle());
			}
		}
	}
	void adicionarArco(int v, int vLlegada) {
		CVertice* ver = vertices->at(v);
		// Comprobar si ya existe un arco a 'vLlegada'
		for (CArco* arco : *ver->ady) {
			if (arco->v == vLlegada) {
				return; // Si ya existe un arco, no añadir uno nuevo
			}
		}
		// Si no existe un arco, añadir uno nuevo
		CArco* arc = new CArco(vacio, vLlegada);
		ver->ady->push_back(arc);
	}
	CVertice* seleccionarVertice(T info) {
		for (typename vector<CVertice*>::iterator it = vertices->begin(); it != vertices->end(); ++it) {
			if ((*it)->info == info) {
				return *it;
			}
		}
		return nullptr;
	}
	void eliminarVertice(T info) {
		for (typename vector<CVertice*>::iterator it = vertices->begin(); it != vertices->end(); ) {
			if ((*it)->info == info) {
				// Eliminar todas las aristas
				for (typename vector<CArco*>::iterator jt = (*it)->ady->begin(); jt != (*it)->ady->end(); ++jt) {
					delete* jt;
				}
				delete (*it)->ady; // Eliminar el vector de adyacencia

				// Eliminar el vértice
				delete* it;
				it = vertices->erase(it);  // Actualizar 'it' después de eliminar el vértice
			}
			else {
				++it;
			}
		}
	}
	bool buscarVertice(T info) {
		for (typename vector<CVertice*>::const_iterator it = vertices->begin(); it != vertices->end(); ++it) {
			if ((*it)->info == info)return true;
		}
		return false;
	}
	int cantidadVertices() { return vertices->size(); }

	void modificarVertice(int v, T info) { ((vertices->at(v))->info) = info; }
	// operaciones del CARCO
	int cantidadArcos(int v) {
		return (vertices->at(v))->ady->size(); // cantidad de arcos de acuerdo al v
	}
	T obtenerArco(int v, int apos) {
		CVertice* ver = vertices->at(v);
		return (ver->ady->at(apos))->info;
	}
	void modificarArco(int v, int apos, T info) {
		CVertice* ver = vertices->at(v);
		(ver->ady->at(apos))->info = info;
	}
	int obtenerVerticeLlegada(int v, int apos) {
		CVertice* ver = vertices->at(v);
		return (ver->ady->at(apos))->v; // indice del vertice de llegada
	}
	void imprimir() const {
		cout << "Grafo:\n";
		for (auto& vertice : *vertices) {
			cout << "Vertice: " << vertice->info << " -> ";
			for (auto& arco : *(vertice->ady)) {  // Usar 'ady' en lugar de 'arcos'
				cout << arco->v << ", ";  // Imprimir el índice del vértice de llegada en lugar del peso del arco
			}
			cout << endl;
		}
	}
	T obtenerVertice(int v) { return (vertices->at(v))->info; }
	void printRelatedComics(const string& titulo) {
		for (CVertice* vertice : *vertices) {
			if (vertice->info->getTitle() == titulo) { // Buscar el vértice con el título de cómic
				for (auto& genreComics : vertice->genreGraph) {
					const string& genero = genreComics.first;
					const vector<string>& relatedComics = genreComics.second;

					cout << "Cómics relacionados con " << titulo << " por género " << genero << ":" << endl;
					for (const string& relatedComic : relatedComics) {
						cout << "- " << relatedComic << endl;
					}
				}
				break; // Salir del bucle una vez que hayas encontrado el vértice
			}
		}
	}
};