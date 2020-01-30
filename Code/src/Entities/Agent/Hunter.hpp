/**
 * @file Hunter.hpp
 * @author Mathieu Arquilliere (mathieu.arquilliere@etu.uca.fr)
 * @brief Fichier de déclaration de la classe Hunter
 * @version 0.1
 * @date 2019-12-26
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#ifndef HUNTER_HPP
#define HUNTER_HPP

#include <random>
#include "Agent.hpp"
#include "../../Utils/World.hpp"
#include "../Entity.hpp"
#include "Harvester.hpp"
#include "../../Observer/Observable.hpp"

/**
 * @brief Classe de l'agent mangeur (Héritant de la classe Entity)
 * L'agent cherche à manger les agents "Harvester". Pour cela il se déplace aléatoirement
 * dans un voisinage de Moore d'ordre 2 et lorsqu'il trouve un Harvester dans ce voisinage
 * il se déplace sur sa case et le mange. Il peut également repérer les Harvesters qui sont
 * dans un voisinage de Moore d'ordre 3.
 * Cet agent possède une vie qui baisse à chaque étape du système. Lorsqu'il mange un Harvester,
 * celle-ci remonte. Si il mange un Harvester avec plus de 80% de sa vie, il donne naissance à
 * un autre Hunter.
 */
class Hunter : public Agent
{
public:
    /**
     * @brief Construit un nouvel objet Hunter
     * 
     * @param[in] p Coordonnées où est créé l'agent
     * @param[in] c Caractère à afficher sur la map pour représenter un Harvester
     */
    Hunter(Point const & p, char c = 'M');

    /**
     * @brief Détruit l'objet Hunter
     */
    ~Hunter();

    /**
     * @brief Méthode définissant le comportement de l'agent
     * 
     * @param[in] harvesters Tableau des Harvesters du système
     * @param[in] map Map représentant l'environnement (sert pour les méthodes de distances)
     */
    void update() override;

    ENTITY_TYPE getType() const override { return ENTITY_TYPE::HUNTER; }

private:
    enum LIFE_STATE
    {
        RED,
        ORANGE,
        GREEN
    };

    LIFE_STATE _lifeState; /*!< Vie de l'agent (représentée par 3 état: critique, normal et bien) */
    int _stepsBeforeChange; /*!< Nombre d'itérations du système avant de changer d'état */

    static constexpr int RED_STATE_DURATION = 5; /*!< Durée de l'état critique si pas de mise à jour (en nombre d'itération du système) */
    static constexpr int ORANGE_STATE_DURATION = 5; /*!< Durée de l'état normal si pas de mise à jour (en nombre d'itération du système) */
    static constexpr int GREEN_STATE_DURATION = 5; /*!< Durée de l'état bien si pas de mise à jour (en nombre d'itération du système) */

    static std::mt19937 gen; /*!< générateur de nombre aléatoire Mersenne Twister (pour le déplacement aléatoire) */
    static std::uniform_int_distribution<> move_distribution; /*!< Distribution pour le déplacement aléatoire */
};

#endif