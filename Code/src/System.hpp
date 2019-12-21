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
#include "Utils/Map.hpp"
#include "Entities/Entity.hpp"
#include "Entities/Agent/Agent.hpp"

/**
 * @brief Classe représentant un système multi-agent
 * C'est cette classe qui va s'occuper de faire agir et interagir les agents et les ressources
 */
class System
{
public:
    /**
     * @brief Construit un nouvel objet System
     * 
     * @param[in] w "hauteur" de la map du système
     * @param[in] h "longeur" de la map du système
     */
    System(int w, int h);

    /**
     * @brief Détruit l'objet System
     */
    ~System();

    /**
     * @brief Ajoute un agent dans le système
     * 
     * @param[in] agent Pointeur sur l'agent à ajouter
     */
    void addAgent(Agent* agent);

    /**
     * @brief Méthode qui actualise tous les agents et donc les fais bouger et intéragir avec leur environnement
     * C'est cette méthode qui sera le coeur du programme
     */
    void update();

    /**
     * @brief Surcharge de l'opérateur <<, permet d'afficher plus simplement la map du système sur un flux
     * 
     * @param[in] out flux sur lequel afficher la map du système
     * @param[in] sys système à afficher
     * @return std::ostream& flux d'entrée, permet le chaînage d'opérateurs
     */
    friend std::ostream& operator<<(std::ostream& out, System const & sys);

private:
    std::vector<Agent*> _agents; /*!< Tableau contenant tous les agents du système */
    Map _map; /*!< Objet map sur lequel on affiche l'ensemble du système */
};

#endif