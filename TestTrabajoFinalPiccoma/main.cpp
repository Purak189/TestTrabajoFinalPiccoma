#include "CGrafo.h"
#include "CComic.h"

int main() {
	setlocale(LC_ALL, "spanish");
	CGrafo<CComic*> grafo;

	CComic* comic1 = new CComic("Spider-Man", "Stan Lee", "2001-01-01", 50, "Superheroes", "Ingles", 50);
	CComic* comic2 = new CComic("Batman", "Bob Kane", "2003-05-15", 60, "Superheroes", "Ingles", 50);
	CComic* comic3 = new CComic("The Walking Dead", "Bob Kane", "2003-05-14", 60, "Horror", "Ingles", 50);
	CComic* comic4 = new CComic("Maus", "Bob Kane", "2003-05-13", 60, "Historia", "Ingles", 50);
	CComic* comic5 = new CComic("La momia", "Bob Kane", "2003-05-11", 60, "Horror", "Ingles", 50);
	CComic* comic6 = new CComic("Flash", "Stan Lee", "2001-01-01", 50, "Superheroes", "Ingles", 50);
	CComic* comic7 = new CComic("Chucky", "Bob Kane", "2003-05-11", 60, "Horror", "Ingles", 50);

	grafo.adicionarVerticeComic(comic1);
	grafo.adicionarVerticeComic(comic2);
	grafo.adicionarVerticeComic(comic3);
	grafo.adicionarVerticeComic(comic4);
	grafo.adicionarVerticeComic(comic5);
	grafo.adicionarVerticeComic(comic6);
	grafo.adicionarVerticeComic(comic7);

	grafo.printRelatedComics("Spider-Man");
	grafo.printRelatedComics("La momia");
	grafo.printRelatedComics("Batman");

	system("pause");
	return 0;
}