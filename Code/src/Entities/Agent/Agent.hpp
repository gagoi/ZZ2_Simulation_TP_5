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

#include "../../Utils/World.hpp"
#include "../../System.hpp"
#include "../Entity.hpp"
#include "../../Observer/Observable.hpp"

class System;

/**
 * @brief Classe abstraite définissant l'interface d'un agent (héritant d'Entity)
 */
class Agent : public Entity, public Observable
{
public:
    /**
     * @brief Construit un nouvel objet Agent
     * 
     * @param[in] p Coordonnées où est créé l'agent
     * @param[in] c Caractère à afficher sur la map pour représenter un Agent
     */
    Agent(Point const & p, char c);

    void setPosition(Point const & p);

    void move(Point const & p);

    bool isDead() const { return _dead; }

    void kill() { _dead = true; }

    /**
     * @brief Détruit l'objet Agent
     */
    ~Agent();

    /**
     * @brief Méthode abstraite, doit définir le comportement à chaque étape du système
     */
    virtual void update() = 0;

private:
    bool _dead;
};

#endif