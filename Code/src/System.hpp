/**
 * @file System.hpp
 * @author Mathieu Arquilliere (mathieu.arquilliere@etu.uca.fr)
 * @brief Fichier de déclaration de la classe System
 * @version 0.1
 * @date 2019-12-21
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#ifndef SYSTEM_HPP
#define SYSTEM_HPP

#include <vector>
#include <iostream>
#include <iomanip>
#include "Utils/World.hpp"
#include "Entities/Agent/Agent.hpp"
#include "Observer/IObserver.hpp"

class Agent;

/**
 * @brief Classe représentant un système multi-agent
 * C'est cette classe qui va s'occuper de faire agir et interagir les agents et les ressources
 */
class System
{
private:
    static System* instance;

public:
    static System& getInstance();
    static void deleteInstance();

    /**
     * @brief Construit un nouvel objet System
     * 
     * @param[in] w "hauteur" de la map du système
     * @param[in] h "longeur" de la map du système
     */
    System();

    /**
     * @brief Détruit l'objet System
     */
    ~System();

    void addAgent(Agent * a);

    /**
     * @brief Méthode qui actualise tous les agents et donc les fais bouger et intéragir avec leur environnement
     * C'est cette méthode qui sera le coeur du programme
     */
    void update();

private:
    std::vector<Agent*> _agents;
    std::vector<Agent*> _addingBuffer;
};

#endif