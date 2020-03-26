/**
 * @file System.hpp
 * @author Mathieu Arquilliere (mathieu.arquilliere@etu.uca.fr), Jeremy Zangla (jeremy.zangla@etu.uca.fr)
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
 * C'est cette classe qui va s'occuper de faire agir et interagir les agents
 * 
 * Cette classe ne contient qu'un tableau d'agents et les updates
 * Cette classe est un singleton
 */
class System
{
private:
    static System* instance; /*!< Instance de System (singleton) */

public:
    /**
     * @brief Getter de l'instance de System (la méthode la créee si elle n'existe pas (singleton))
     * 
     * @return System& instance de System
     */
    static System& getInstance();

    /**
     * @brief Libère la mémoire utilisée par l'instance de System
     */
    static void deleteInstance();

    /**
     * @brief Construit un nouvel objet System
     */
    System();

    /**
     * @brief Détruit l'objet System
     */
    ~System();

    /**
     * @brief Méthode ajoutant un agent au systeme
     * 
     * @param[in] a agent
     */
    void addAgent(Agent * a);

    /**
     * @brief Méthode qui actualise tous les agents et donc les fais bouger et intéragir avec leur environnement
     * C'est cette méthode qui sera le coeur du programme
     */
    void update();

private:
    std::vector<Agent*> _agents; /*!< Tableau contenant les agents du syteme */
    std::vector<Agent*> _addingBuffer; /*!< Tableau contenant les agents à ajouter au prochain update */
};

#endif