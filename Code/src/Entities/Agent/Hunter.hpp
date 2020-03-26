/**
 * @file Hunter.hpp
 * @author Mathieu Arquilliere (mathieu.arquilliere@etu.uca.fr), Jeremy Zangla (jeremy.zangla@etu.uca.fr)
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
#include "../../colors.hpp"
#include "Agent.hpp"
#include "../../Utils/World.hpp"
#include "../Entity.hpp"
#include "Harvester.hpp"
#include "../../Observer/Observable.hpp"

/**
 * @brief Classe de l'agent mangeur (Héritant de la classe Agent)
 * Comportement :
 *      L'agent cherche à manger les agents "Harvester". Pour cela il se déplace aléatoirement
 *      dans un voisinage de Moore d'ordre 2 et lorsqu'il trouve un Harvester dans ce voisinage
 *      il se déplace sur sa case et le mange. Il peut également repérer les Harvesters qui sont
 *      dans un voisinage de Moore d'ordre 3.
 *      Cet agent possède une vie (soit ROUGE, soit ORANGE, soit VERT). Lorsqu'il mange un Harvester,
 *      celle-ci monte. Si il mange un Harvester dans l'état VERT, il donne naissance à
 *      un autre Hunter. Si il ne mange pas pendant un certain temps, sa vie descend et si il est il
 *      ne mange pas alors qu'il est en ROUGE, il meurt.
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
     */
    void update() override;


    std::string getColor() const override;

    /**
     * @brief Getter de Type 
     * 
     * @return ENTITY_TYPE type de l'entité
     */
    ENTITY_TYPE getType() const override { return ENTITY_TYPE::HUNTER; }

private:
    /**
     * @brief enum définissant les différents états de vie du Hunter
     */
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
};

#endif