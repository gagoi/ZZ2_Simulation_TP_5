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
#include "../../Utils/World.hpp"
#include "Agent.hpp"
#include "../Entity.hpp"
#include "../Resource.hpp"
#include "../Base.hpp"

class Base;

/**
 * @brief Classe de l'agent récolteur (héritant de la classe Entity)
 * L'agent est créé par une base et est lié à celle-ci.
 * Comportement :
 *      L'Harvester a 2 états, recherche et livraison
 *      Dans le premier, l'agent se déplace aléatoirement dans un voisinage de Moore d'ordre 1. Il le fait jusqu'à se trouver sur une case contenant une ressource
 *      Une fois sur une ressource, il prends celle-ci et se déplace au plus court vers sa base où il dépose ses ressources.
 */
class Harvester : public Agent
{
public:
    /**
     * @brief Construit un nouvel agent Harvester
     * 
     * @param[in] p Coordonnées où est créé l'agent
     * @param[in] base Base de l'agent
     * @param[in] c Caractère à afficher sur la map pour représenter un Harvester
     */
    Harvester(Point const & p, Base* base, char c = 'H');

    /**
     * @brief Détruit l'objet Harvester
     */
    ~Harvester();

    /**
     * @brief Méthode appelée à chaque étape du système pour déplacer l'agent
     *      Aléatoirement si il est dans l'état SEARCHING
     *      Vers sa base si il est dans l'état BRINGING 
     */
    void randomMove();

    /**
     * @brief Méthode définissant le comportement de l'agent à chaque étape du système
     * 
     * @param[in] resources Tableau d'entité contenant les ressources
     * @param[in] map Map représentant l'environnement (sert pour les méthodes de distances)
     */
    void update() override;

    /**
     * @brief Getter de la base de l'agent
     * 
     * @return Base* const Pointeur sur la base de l'agent
     */
    Base* const getBase() const;

    virtual ENTITY_TYPE getType() const override { return ENTITY_TYPE::HARVESTER; }

private:
    /**
     * @brief enum définissant les états possibles de l'agent 
     */
    enum class STATE
    {
        SEARCH,
        BRING
    };

    Base* _base; /*!< Base de l'agent */
    STATE _state; /*!< Etat de l'agent */

    static std::mt19937 gen; /*!< générateur de nombre aléatoire Mersenne Twister (pour le déplacement aléatoire) */
    static std::uniform_int_distribution<> move_distribution; /*!< Distribution pour le déplacement aléatoire */
};

#endif