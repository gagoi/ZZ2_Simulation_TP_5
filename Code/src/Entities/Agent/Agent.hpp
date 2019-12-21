/**
 * @file Agent.hpp
 * @author Mathieu Arquilliere (mathieu.arquilliere@etu.uca.fr)
 * @brief Fichier de déclaration de la classe Agent
 * @version 0.1
 * @date 2019-12-21
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#ifndef AGENT_HPP
#define AGENT_HPP

#include "../Entity.hpp"

/**
 * @brief Classe abstraite définissant l'interface d'un agent (héritant d'Entity)
 */
class Agent : public Entity
{
public:
    /**
     * @brief Construit un nouvel objet Agent
     * 
     * @param[in] p Coordonnées où est créé l'agent
     * @param[in] c Caractère à afficher sur la map pour représenter un Agent
     */
    Agent(Point const & p, char c);

    /**
     * @brief Détruit l'objet Agent
     */
    ~Agent();

    /**
     * @brief Méthode abstraite, un agent doit pouvoir se déplacer dans l'environnement 
     */
    virtual void move() = 0;

    /**
     * @brief Méthode abstraite, doit définir le comportement à chaque étape du système
     */
    virtual void update() = 0;
};

#endif