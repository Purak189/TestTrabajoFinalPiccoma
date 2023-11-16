#pragma once
#ifndef CRevista_H_
#define CRevista_H_
#pragma once
#include<iostream>
#include<string>
#include<ctime>
#include<functional>
#include<type_traits>
#include<stdexcept>
using namespace std;
class CRevista {
public:
	CRevista();
	CRevista(long id, int paginas, string autor, string fechaPublicacion);
	CRevista(long id, string titulo, string autor, string fechaPublicacion,
		int paginas, string genero);
	CRevista(string titulo, string autor, string fechaPublicacion,
		int paginas, string genero, string idioma, float precio);
	CRevista(long id, string titulo, string autor, string fechaPublicacion,
		int paginas, string genero, string ranking, string cuestionarios, string texto, string idioma, string descubre,
		string favoritos, string credenciales, float precio, string portada, string descripcion);
	~CRevista();
	bool isPublico();
	bool isPrivate();
	// void calcularPromedioCalificacion();
	long getID();
	string gettitulo();
	string getautor();
	string getfechaPublicacion();
	int getpaginas();
	string getgenero();
	string getranking();
	string getcuestionarios();
	string gettexto();
	string getidioma();
	string getdescubre();
	string getfavoritos();
	string getcredenciales();
	float getprecio();
	string getportada();
	string getdescripcion();
	void settitulo(string titulo);
	void setautor(string autor);
	void setfechaPublicacion(string fechaPublicacion);
	void setpaginas(int paginas);
	void setgenero(string genero);
	void setranking(string ranking);
	void setcuestionarios(string cuestionarios);
	void settexto(string texto);
	void setidioma(string idioma);
	void setdescubre(string descubre);
	void setfavoritos(string favoritos);
	void setcredenciales(string credenciales);
	void setprecio(float setprecio);
	void setportada(string setportada);
	void setdescripcion(string setdescripcion);
protected:
	long id;
	string titulo;
	string autor;
	string fechaPublicacion;
	int paginas;
	string genero;
	string ranking;
	string cuestionarios;
	string texto;
	string idioma;
	string descubre;
	string favoritos;
	string credenciales;
	float precio;
	string portada;
	string descripcion;
};
CRevista::CRevista() {
	this->id = ((rand() * rand()) % (99999999 + 10000001)) + 10000000;
	this->titulo = "";
	this->autor = "";
	this->fechaPublicacion = "";
	this->paginas = 0;
	this->genero = "";
	this->ranking = "";
	this->cuestionarios = "";
	this->texto = "";
	this->idioma = "";
	this->descubre = "";
	this->favoritos = "";
	this->credenciales = "";
	this->precio = 0.0;
	this->portada = "";
	this->descripcion = "";
}
CRevista::CRevista(long id, string titulo, string autor, string fechaPublicacion,
	int paginas, string genero) {
	this->id = id;
	this->titulo = titulo;
	this->autor = autor;
	this->fechaPublicacion = fechaPublicacion;
	this->paginas = paginas;
	this->genero = genero;
	this->ranking = "";
	this->cuestionarios = "";
	this->texto = "";
	this->idioma = "";
	this->descubre = "";
	this->favoritos = "";
	this->credenciales = "";
	this->precio = 0.0;
	this->portada = "";
	this->descripcion = "";
}
CRevista::CRevista(string titulo, string autor, string fechaPublicacion,
	int paginas, string genero, string idioma, float precio) {
	this->id = ((rand() * rand()) % (99999999 + 10000001)) + 10000000;
	this->titulo = titulo;
	this->autor = autor;
	this->fechaPublicacion = fechaPublicacion;
	this->paginas = paginas;
	this->genero = genero;
	this->ranking = "";
	this->cuestionarios = "";
	this->texto = "";
	this->idioma = idioma;
	this->descubre = "";
	this->favoritos = "";
	this->credenciales = "";
	this->precio = precio;
	this->portada = "";
	this->descripcion = "";
}
CRevista::CRevista(long id, int paginas, string autor, string fechaPublicacion) {
	this->id = id;
	this->titulo = "";
	this->autor = autor;
	this->fechaPublicacion = fechaPublicacion;
	this->paginas = paginas;
	this->genero = "";
	this->ranking = "";
	this->cuestionarios = "";
	this->texto = "";
	this->idioma = "";
	this->descubre = "";
	this->favoritos = "";
	this->credenciales = "";
	this->precio = 0.0;
	this->portada = "";
	this->descripcion = "";
}
CRevista::CRevista(long id, string titulo, string autor, string fechaPublicacion,
	int paginas, string genero, string ranking, string cuestionarios, string texto, string idioma, string descubre,
	string favoritos, string credenciales, float precio, string portada, string descripcion) {
	this->id = id;
	this->titulo = titulo;
	this->autor = autor;
	this->fechaPublicacion = fechaPublicacion;
	this->paginas = paginas;
	this->genero = genero;
	this->ranking = ranking;
	this->cuestionarios = cuestionarios;
	this->texto = texto;
	this->idioma = idioma;
	this->descubre = descubre;
	this->favoritos = favoritos;
	this->credenciales = credenciales;
	this->precio = precio;
	this->portada = portada;
	this->descripcion = descripcion;
}
CRevista::~CRevista() {}
bool CRevista::isPublico() { return true; }
bool CRevista::isPrivate() { return false; }
long CRevista::getID() { return id; }
string CRevista::gettitulo() { return titulo; }
string CRevista::getautor() { return autor; }
string CRevista::getfechaPublicacion() { return fechaPublicacion; }
int CRevista::getpaginas() { return paginas; }
string CRevista::getgenero() { return genero; }
string CRevista::getranking() { return ranking; }
string CRevista::getcuestionarios() { return cuestionarios; }
string CRevista::gettexto() { return texto; }
string CRevista::getidioma() { return idioma; }
string CRevista::getdescubre() { return descubre; }
string CRevista::getfavoritos() { return favoritos; }
string CRevista::getcredenciales() { return credenciales; }
float CRevista::getprecio() { return precio; }
string CRevista::getportada() { return portada; }
string CRevista::getdescripcion() { return descripcion; }
void CRevista::settitulo(string titulo) { this->titulo = titulo; }
void CRevista::setautor(string autor) { this->autor = autor; }
void CRevista::setfechaPublicacion(string fechaPublicacion) { this->fechaPublicacion = fechaPublicacion; }
void CRevista::setpaginas(int paginas) { this->paginas = paginas; }
void CRevista::setgenero(string genero) { this->genero = genero; }
void CRevista::setranking(string ranking) { this->ranking = ranking; }
void CRevista::setcuestionarios(string cuestionarios) { this->cuestionarios = cuestionarios; }
void CRevista::settexto(string texto) { this->texto = texto; }
void CRevista::setidioma(string idioma) { this->idioma = idioma; }
void CRevista::setdescubre(string descubre) { this->descubre = descubre; }
void CRevista::setfavoritos(string favoritos) { this->favoritos = favoritos; }
void CRevista::setcredenciales(string credenciales) { this->credenciales = credenciales; }
void CRevista::setprecio(float precio) { this->precio = precio; }
void CRevista::setportada(string portada) { this->portada = portada; }
void CRevista::setdescripcion(string descripcion) { this->descripcion = descripcion; }
#endif // !CRevista_H_
