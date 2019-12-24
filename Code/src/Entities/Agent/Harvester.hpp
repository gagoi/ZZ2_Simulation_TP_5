/**
 * @file Harvester.hpp
 * @author Mathieu Arquilliere (mathieu.arquilliere@etu.uca.fr)
 * @brief Fichier de déclaration de la classe Harvester
 * @version 0.1
 * @date 2019-12-21
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#ifndef HARVESTER_HPP
#define HARVESTER_HPP

#include <random>
#include "../Entity.hpp"
#include "../Resource.hpp"

/**
 * @brief Classe de l'agent récolteur (héritant de la classe Agent) TODO: /!\ Héritage classe Entity
 * L'agent est créé par une base et est lié à celle-ci.
 * Comportement :
 *      L'Harvester a 2 états, recherche et livraison
 *      Dans le premier, l'agent se déplace aléatoirement dans un voisinage de Moore d'ordre 1. Il le fait jusqu'à se trouver sur une case contenant une ressource
 *      Une fois sur une ressource, il prends celle-ci et se déplace au plus court vers sa base où il dépose ses ressources.
 */
class Harvester : public Entity
{
public:
    /**
     * @brief Construit un nouvel agent Harvester
     * 
     * @param[in] p Coordonnées où est créé l'agent
     * @param[in] basePos Coordonnées de la base de l'agent 
     * @param[in] c Caractère à afficher sur la map pour représenter un Harvester
     */
    Harvester(Point const & p, Point const & basePos, char c = 'H');

    /**
     * @brief Détruit l'objet Harvester
     */
    ~Harvester();

    /**
     * @brief Méthode appelée à chaque étape du système pour déplacer l'agent
     *      Aléatoirement si il est dans l'état SEARCHING
     *      Vers sa base si il est dans l'état BRINGING 
     */
    void move(Map const & map);

    /**
     * @brief Méthode définissant le comportement de l'agent à chaque étape du système
     * 
     * @param[in] resources Tableau d'entité contenant les ressources
     */
    void update(std::vector<Resource*> & resources, Map const & map);

private:
    /**
     * @brief enum définissant les états possibles de l'agent 
     */
    enum class STATE
    {
        SEARCH,
        BRING
    };

    Point _basePosition; /*!< Coordonnées de la base de l'agent */
    STATE _state; /*!< Etat de l'agent */

    static std::mt19937 gen; /*!< générateur de nombre aléatoire Mersenne Twister (pour le déplacement aléatoire) */
    static std::uniform_int_distribution<> move_distribution; /*!< Distribution pour le déplacement aléatoire */
};

#endif