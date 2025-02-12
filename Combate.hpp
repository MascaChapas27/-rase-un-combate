#ifndef __COMBATE_HPP__
#define __COMBATE_HPP__

#include "Personaje.hpp"
#include "Enums.hpp"
#include "GUIPersonaje.hpp"
#include "Escenario.hpp"
#include "AnimacionAgrandable.hpp"

/*
    Esta clase define un combate, formado por dos jugadores, cada
    uno manejando un personaje. El combate tiene varias rondas,
    las cuales terminan cuando uno de los personajes llega a 0 puntos de
    vida. A las 2 rondas ganadas por parte de uno de los personajes, el
    combate termina.
*/
class Combate{
    private:

        // Personaje asignado al jugador 1
        Personaje personajeJugador1;

        // Personaje asignado al jugador 2
        Personaje personajeJugador2;

        // GUI para el personaje asignado al jugador 1
        GUIPersonaje GUIJugador1;

        // GUI para el personaje asignado al jugador 2
        GUIPersonaje GUIJugador2;

        // Escenario para el combate
        Escenario escenario;

        // Rectángulo negro que aparece antes de que empiece el combate y entre rondas
        sf::RectangleShape rectanguloOscuro;

        // Ronda actual
        int numeroRonda;

        // Indica qué jugador se debe actualizar primero en el turno actual. Esto sirve para que no sea
        // siempre el primer jugador el que se actualiza primero, causando situaciones raras e injustas
        Jugador primerJugadorParaActualizar;

        // Cartel que aparece al principio de la ronda en el que pone "¿Todo listo?"
        std::shared_ptr<Animacion> cartelTodoListo;

        // Cartel que aparece al principio de la ronda en el que pone "¡A pelear!"
        std::shared_ptr<Animacion> cartelAPelear;

        // Cartel que aparece al terminar una ronda en el que pone "¡Gana el jugador 1!"
        std::shared_ptr<Animacion> cartelGanaJugador1;

        // Cartel que aparece al terminar una ronda en el que pone "¡Gana el jugador 2!"
        std::shared_ptr<Animacion> cartelGanaJugador2;

    private:
        // Devuelve todo a la normalidad para la siguiente ronda (excepto el contador
        // de rondas ganadas de cada GUI de personaje)
        void resetear();

        // Actualiza un frame del combate, pero solo cuando al menos uno de los personajes está preparando
        // su súper ataque (el fondo se oscurece y nadie se puede mover)
        void actualizarFramePreparandoSuper(std::list<std::shared_ptr<Animacion>> &efectos);

        // Actualiza un frame completamente normal y corriente del combate
        void actualizarFrameNormal(std::list<std::shared_ptr<Animacion>> &efectos);

        // Actualiza un frame pero solo cuando uno de los personajes está KO y el otro celebra. Se encarga de actualizar contadorCelebracion
        void actualizarFrameCelebracion(std::list<std::shared_ptr<Animacion>> &efectos, int &contadorCelebracion, Personaje &ganador);

        // TODO
        // void actualizarFrameEmpate(int &contadorCelebracion);

        // Sé que el nombre es largo de cojones pero no se me ocurre otra cosa mejor. Actualiza como su propio nombre indica
        // los dos personajes, los efectos, las GUIs, el escenario y la ventana. No comprueba colisiones, y no inserta nuevos
        // efectos en la lista de efectos (los efectos nuevos se quedan en nuevosEfectos hasta que se vayan a meter luego)
        void actualizarPersonajesEfectosGuisEscenarioVentana(std::list<std::shared_ptr<Animacion>> &efectos, std::list<std::shared_ptr<Animacion>> &nuevosEfectos);

        // Procesa los eventos generados en la ventana actual e informa a los personajes para que se muevan
        void recibirEntrada();

    public:

        // Construye el combate en base a los nombres de los personajes
        // y del escenario en el que se va a pelear. Lo demás es común a todos
        // los combates
        Combate(std::string nombrePersonajeJ1, std::string nombrePersonajeJ2, std::string nombreEscenario);

        // Comienza el combate (la clase pasa a tomar el control de
        // la ventana principal hasta que termine el combate)
        void comenzar();

};

#endif // __COMBATE_HPP__
