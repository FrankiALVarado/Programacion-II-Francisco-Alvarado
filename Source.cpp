#include <iostream>

using std::cin;
using std::cout;
using std::endl;

class cHuman_being;
class cPersona;
class cDueño;
class cDog;

class cHuman_being // interfaz
{
	
public:
	virtual void Set_Name(const char * name) = 0;
	virtual void Get_Name() = 0;
	virtual void Set_Age(const int & age) = 0;
	virtual void Get_Age() = 0;

};

class cPersona : public cHuman_being { // heredar funciones de una interfaz

protected:
	const char * m_Name;
	int m_Age;
public:
	 void Set_Name(const char * name) { m_Name = name; }//
     void Get_Name() { cout << m_Name << endl; }// Funciones 
     void Set_Age(const int & age) { m_Age = age; } // Aplicadas
	 void Get_Age() { cout << m_Age << endl; }//
	
};

class cAnimal // clase abstracta
{
protected:
	const char *m_name;

public:
	virtual void Set_name(const char *name) = 0;
	virtual void Get_name() { cout << "Joey" << endl; }
};


class cDueño
{
public:
	void nameDog(cDog &d, const char *name);

};

class cDog : public cAnimal
{
	friend class cDueño;
protected:
	const char *m_name;

public:
	void Set_name(const char *name) { m_name = name; }
	void Get_name() { cout << m_name << endl; }
};

int main() {
	// Interfaz
	//-----------------------------------------------------------------------------------
	cout << "Clase Persona heredando de la interfaz Human being" << endl;
	cPersona P1;
	P1.Set_Name("Rob");
	P1.Set_Age(25);
	P1.Get_Name();
	P1.Get_Age();
	//-----------------------------------------------------------------------------------
	cout << endl;

	cout << "clase perro heredando de la clase concreta animal" << endl;
	cDog perro;
	cAnimal *animal;
	animal = &perro;

	cout << "puntero de clase animal para usar las funciones de la misma clase" << endl;
	animal->Set_name("Dogo"); // imprime el nombre por defecto de animal
	animal->Get_name(); // por defecto va a llamar joey 
	perro.Set_name("pepe"); // perro seteara su nombre a pepe
	perro.Get_name(); // perro imprime su nombre
	//no se como hacer o si es posible que animal imprima el nombre del perro

	//------------------------------------------------------------------
	cDog perro2;
	cDueño Mike;

	Mike.nameDog(perro2, "Miguelito"); // dueño mike nombra a perro 2 como Miguelito
	perro2.Get_name();

	cin.get();
	return 0;
}

void cDueño::nameDog(cDog & d,const char *name)
{
	d.m_name = name; 
}