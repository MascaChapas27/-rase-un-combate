#ifndef __ANIMACION_HPP__
#define __ANIMACION_HPP__

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

/*
    Clase abstracta para cualquier tipo de animaciones
*/
class Animacion : public sf::Drawable {
    protected:
        // Sprite para la animación
        sf::Sprite sprite;

        // Sonido para la animación
        sf::Sound sonido;

    public:

        // Actualiza la animación (avanza un frame)
        virtual void actualizar() = 0;

        // Resetea la animación al estado inicial
        virtual void resetear() = 0;

        // Le da la vuelta al sprite
        virtual void voltear();

        // Coloca el sprite en la posición indicada con respecto a la esquina superior
        // izquierda de la ventana
        void setPosicion(float x, float y);
        void setPosicion(sf::Vector2f posicion);

        // Devuelve la posición actual del sprite
        sf::Vector2f getPosicion();

        // Mueve la posición del sprite con respecto a la posición actual
        void mover(float x, float y);
        void mover(sf::Vector2f diferencia);

        // Determina si una animación ha terminado
        virtual bool haTerminado() = 0;

        // Devuelve un clon de la animación
        virtual Animacion * clonar() = 0;

        // Las clases que heredan de sf::Drawable deben implementar draw
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

#endif // __ANIMACION_HPP__
