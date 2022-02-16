#if 0
//VT 98 COD.001

#include <iostream>

int main()
{
    enum Color
    {
        amarillo,
        azul,
    };

    enum Animal
    {
        perro,
        gato,
    };

    Color color{ azul };
    Animal animal{ gato };

    if (color == animal) // el compilador comparará color y animal como integers
        std::cout << "color y animal son iguales\n"; // y determina que son iguales
    else
        std::cout << "color y animal no son iguales\n";

    return 0;
}




//VT 98 COD.002
#include <iostream>
int main()
{
    enum class Color // "enum class" define esto como una enumeración con ámbito
    {
        amarillo, // amarillo se considera parte del ámbito de Color
        azul,
    };

    enum class Animal
    {
        perro, // perro se considera parte del ámbito de Animal
        gato,
    };

    Color color{ Color::amarillo }; // nota: amarillo no es accesible directamente, tenemos que usar Color::amarillo
    Animal animal { Animal::perro }; // nota: perro no es accesible directamente, tenemos que usar Animal::perro

    if (color == animal) // error de compilación: el compilador no puede comparar tipos diferentes como Color y Animal
        std::cout << "color y animal son iguales\n";
    else
        std::cout << "color y animal no son iguales\n";

    return 0;
}



//VT 98 COD.003
#include <iostream>

int main()
{
    enum class Color // "enum class" define esto como una enumeración con ámbito
    {
        amarillo, // amarillo se considera parte de la región de alcance de Color
        azul,    //  azul se considera parte de la región de alcance de Color
    };

    std::cout << amarillo;        // error compilación: amarillo no está definido en esta región de alcance
    std::cout << Color::amarillo; // error compilación: std::cout no sabe como imprimir esto (no convierte implícitamente a int)
    Color color{ Color::amarillo }; // correcto, pero no imprimible. std::cout sigue sin saber como imprimirlo
    return 0;
}




//VT 98 COD.004
#include <iostream>
int main()
{
    enum class Color
    {
        amarillo,
        azul,
    };

    Color bicicleta{ Color::azul };

    if (bicicleta == Color::amarillo) // este Color para comparar colores es correcto
        std::cout << "La bicicleta es amarilla\n";
    else if (bicicleta == Color::azul)
        std::cout << "La bicicleta es azul\n";

    return 0;
}


//VT 98 COD.005
#include <iostream>

enum class Animal
{
    gato,    //asignado 0
    perro,   //asignado 1
    caballo, // asignado 2
    ballena, // asignado 3
};

int main()
{
    std::cout << "Escribe un animal (0=gato, 1=perro, 2=caballo, 3=ballena): ";

    int input{};
    std::cin >> input; // escribe un integer

    Animal animal{ static_cast<Animal>(input) }; // static_cast el integer a un Pet

    return 0;
}






//VT 98 COD.006
#include <iostream>
int main()
{
    enum class Color
    {
        amarillo,
        azul,
    };

    Color color{ Color::azul };

    std::cout << color; // no funcionará porque no hay conversión implícita a int
    std::cout << static_cast<int>(color); // imprimirá 1

    return 0;
}

//VT 98 COD.007
#include <iostream>

enum class Animal
{
    gato,    //asignado 0
    perro,   //asignado 1
    caballo, // asignado 2
    ballena, // asignado 3
};

void convert(Animal animal) {
    if (animal == Animal::gato) {
        std::cout << "gato";
    }
    else if (animal == Animal::perro) {
        std::cout << "perro";
    }
    else if (animal == Animal::caballo) {
        std::cout << "caballo";
    }
    else if (animal == Animal::ballena) {
        std::cout << "ballena";
    }
    

}

int main()
{
    std::cout << "Escribe un animal (0=gato, 1=perro, 2=caballo, 3=ballena): ";

    int input{};
    std::cin >> input; // escribe un integer

    convert({ static_cast<Animal>(input) }); 
    
   

    return 0;
}
#endif

//VT 98 COD.008
#include <iostream>

enum Animal : int // especificamos una base
{
    gato, // asignado 0
    perro, // asignado 1
    caballo, // asignado 2
    ballena, // asignado 3
};

int main()
{
    Animal animal{ 2 }; // ok: podemos inicializar con un integer
    animal = 3;       // error compilación: no podemos asignar con un integer

    return 0;
}

//VT 98 COD.009
#include <iostream>

enum class Animal // especificamos una base
{
    gato, // asignado 0
    perro, // asignado 1
    caballo, // asignado 2
    ballena, // asignado 3
};

int main()
{
    Animal animal{ 2 }; // ok: podemos inicializar con un integer
    animal = 3;       // error compilación: no podemos asignar con un integer

    return 0;
}







