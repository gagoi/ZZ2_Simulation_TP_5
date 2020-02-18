/**
 * @file Agent.hpp
 * @author Mathieu Arquilliere (mathieu.arquilliere@etu.uca.fr), Jeremy Zangla (jeremy.zangla@etu.uca.fr)
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
 * Cette classe hérite également de l'objet Observable pour la mise en place du patron Observer
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

    /**
     * @brief Setter de Position
     * 
     * @param[in] p nouvelle position de l'agent
     */
    void setPosition(Point const & p);

    /**
     * @brief Permet à l'agent de changer de bouger sur la map
     * 
     * @param[in] p nouvelle position (relative à sa position actuelle)
     */
    void move(Point const & p);

    /**
     * @brief Getter de _dead, permet de savoir si l'agent doit sortir du système
     * 
     * @return true l'agent est techniquement mort (mais encore dans le système)
     * @return false l'agent est toujours vivant
     */
    bool isDead() const { return _dead; }

    /**
     * @brief tue l'agent (mais ne le retire pas du système)
     */
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
    bool _dead; /*!< Booleen déterminant si l'agent est mort ou non */
};

#endif