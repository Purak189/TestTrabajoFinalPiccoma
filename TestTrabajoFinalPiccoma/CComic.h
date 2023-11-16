#pragma once
#ifndef CComic_H_
#define CComic_H_
#include"CRevista.h"
string arrTituloComic[40] = {
        "Spider-Man     ",
        "Batman         ",
        "Wonder Woman   ",
        "X-Men          ",
        "Iron Man       ",
        "Avengers       ",
        "Black Widow    ",
        "Thor           ",
        "Superman       ",
        "Guardians      ",
        "The Flash      ",
        "Aquaman        ",
        "Captain America",
        "Deadpool       ",
        "Green Lantern  ",
        "Hulk           ",
        "Justice League ",
        "Fantastic Four ",
        "Doctor Strange ",
        "Green Arrow    ",
        "The Punisher   ",
        "Catwoman       ",
        "Daredevil      ",
        "Wolverine      ",
        "Harley Quinn   ",
        "The Walking Dea",
        "The Sandman    ",
        "Spawn          ",
        "Teen Titans    ",
        "Hellboy        ",
        "The Witcher    ",
        "Sonic the Hedge",
        "The Boys       ",
        "Saga           ",
        "Locke & Key    ",
        "Transmetropolit",
        "Silver Surfer  ",
        "Spawn          ",
        "Moon Knight    ",
        "Supergirl      ",
};
string arrEditorialComic[40] = {
        "Marvel Comics    ",
        "DC Comics        ",
        "Image Comics     ",
        "Dark Horse Comics",
        "IDW Publishing   ",
        "BOOM! Studios    ",
        "Dynamite         ",
        "Valiant Comics   ",
        "Archie Comics    ",
        "Aftershock Comics",
        "Top Productions  ",
        "Oni Press        ",
        "Vertigo Comics   ",
        "Fantagraphics    ",
        "Black Mask       ",
        "First Second     ",
        "Humanoids Publish",
        "Zenescope        ",
        "Abstract Studio  ",
        "Red 5 Comics     ",
        "IDW Publishing   ",
        "Viz Media        ",
        "Dark Horse Comics",
        "Valiant Comics   ",
        "Dover Publication",
        "BOOM! Studios    ",
        "Archie Comics    ",
        "Top Cow Productio",
        "Avatar Press     ",
        "Dargaud          ",
        "HarperCollins    ",
        "Kodansha         ",
        "Valiant Comics   ",
        "Hermes Press     ",
        "Drawn & Quarterly",
        "Oni Press        ",
        "Zenescope        ",
        "Image Comics     ",
        "Archie Comics    ",
        "Dark Horse Comics"
};
string arrAutoresComic[40] = {
        "Stan Lee     ",
        "Jack Kirby   ",
        "Frank Miller ",
        "Alan Moore   ",
        "Neil Gaiman  ",
        "Grant Morriso",
        "Brian K. Vaug",
        "Frank Quitely",
        "Will Eisner  ",
        "Chris Claremo",
        "Jim Lee      ",
        "Dave Gibbons ",
        "Mike Mignola ",
        "Todd McFarlan",
        "Mark Millar  ",
        "Geoff Johns  ",
        "Warren Ellis ",
        "Robert Kirkma",
        "Alan Davis   ",
        "Garth Ennis  ",
        "Alan Moore   ",
        "Frank Miller ",
        "Mike Mignola ",
        "Brian Michael",
        "Chris Ware   ",
        "Osamu Tezuka ",
        "Gosho Aoyama ",
        "Nobuhiro Wats",
        "Leiji Matsumo",
        "Naoki Urasawa",
        "Hajime Isayam",
        "Rumiko Takaha",
        "Yoshihiro Tog",
        "Eiichiro Oda ",
        "Hiromu Arakaw",
        "Makoto Yukimu",
        "Katsuhiro Oto",
        "Junji Ito    ",
        "Ukumi Karutzi",
        "Jaitama Koku "
};

class CComic : public CRevista {
public:
    CComic();
    CComic(string titulo, int paginas, string genero, string descripcion);
    CComic(string titulo, string autor, string fechaPublicacion, int paginas, string genero, string idioma, float precio);
    CComic(string autor);
    ~CComic();
    string getEditorial();
    int getCapitulo();
    void setEditorial(string editorial);
    void setCapitulo(int capitulo);
    const string& getGenre() const {
        return genero;
    }

    const string& getTitle() const {
        return titulo;
    }
private:
    string editorial;
    int capitulo;
};

CComic::CComic() : CRevista() {
    this->id = ((rand() * rand()) % (100000 + 1000)) + 1000;
    this->autor = arrAutoresComic[rand() % 40];
    this->titulo = arrTituloComic[rand() % 40];
    this->editorial = arrEditorialComic[rand() % 40];
    this->paginas = rand() % 120;
    this->genero = "comic";
    this->descripcion = "";
    this->capitulo = rand() % 80;
}
CComic::CComic(string autor) {
    this->id = ((rand() * rand()) % (100000 + 1000)) + 1000;
    this->autor = autor;
    this->titulo = arrTituloComic[rand() % 40];
    this->editorial = arrEditorialComic[rand() % 40];
    this->paginas = rand() % 120;
    this->genero = "comic";
    this->descripcion = "";
    this->capitulo = rand() % 80;
}
CComic::CComic(string titulo, string autor, string fechaPublicacion, int paginas,
    string genero, string idioma, float precio) : CRevista(titulo, autor, fechaPublicacion, paginas,
        genero, idioma, precio) {
    this->editorial = "";
    this->capitulo = 0;
}
CComic::CComic(string titulo, int paginas, string genero, string descripcion) {
    this->titulo = titulo;
    this->paginas = paginas;
    this->genero = genero;
    this->descripcion = descripcion;
    this->editorial = "";
    this->capitulo = 0;
}
CComic::~CComic() {}
string CComic::getEditorial() { return editorial; }
int CComic::getCapitulo() { return capitulo; }
void CComic::setEditorial(string editorial) { this->editorial = editorial; }
void CComic::setCapitulo(int capitulo) { this->capitulo = capitulo; }
#endif // !CComic_H_
