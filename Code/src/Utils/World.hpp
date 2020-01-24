/**
 * @file World.hpp
 * @author Mathieu Arquilliere (mathieu.arquilliere@etu.uca.fr)
 * @brief Fichier de déclaration de la classe World
 * @version 0.1
 * @date 2019-12-21
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#ifndef World_HPP
#define World_HPP

#include <vector>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <random>
#include <iterator>
#include "Point.hpp"
#include "../Entities/Entity.hpp"
#include "../Observer/IObserver.hpp"

extern std::mt19937 gen;

/**
 * @brief Classe World
 * 
 * Classe implémentant une interface d'un double tableau de caractère.
 * Cette classe permet de simplifier l'accès à l'affichage de l'environnement du système d'agents.
 * La fonctionnalité principale est qu'un objet World est un "tore" (le haut est relié au bas et la gauche à la droite)
 */
class World : public IObserver
{
private:
    static World* instance;

public:
    static constexpr int WORLD_WIDTH = 20;
    static constexpr int WORLD_HEIGHT = 20;

    static World& getInstance();

    /**
     * @brief Construit un nouvel objet World
     * 
     * @param[in] a nombre de "lignes" de la World
     * @param[in] b nombre de "colonnes" de la World
     */
    World();

    /**
     * @brief Détruit l'objet World
     */
    ~World();

    void add(Entity* entity);

    std::vector<Entity*> getEnvironment(Point & origin, int range);

    bool findRandomPositionInEnvironment(std::vector<Entity*> env, Point const & origin, int range, Entity::ENTITY_TYPE toFind, Point & pos);

    void updateMove(Entity * e, Point const & newPosition);

    void updateDelete(Entity * e);

    void refactorCoordonates(Point & p);

    /**
     * @brief Getter de _width 
     * 
     * @return int nombre de "lignes" de la World
     */
    int getWidth() const { return _width; }

    /**
     * @brief Getter de _height 
     * 
     * @return int nombre de "colonnes" de la World
     */
    int getHeight() const { return _height; }

    /**
     * @brief surcharge de l'opérateur [], permet d'accéder et de modifier un caractère de la World
     * 
     * @param[in] p un point contenant les coordonnées du caractère à modifier
     * @return char& référence sur le caractère à la position p de la World
     */
    Entity*& operator[](Point const & p);

    /**
     * @brief surcharge de l'opérateur [], permet d'accéder uniquement en lecture à un caractère de la World
     * 
     * @param[in] p un point contenant les coordonnées du caractère à obtenir
     * @return char& référence constante sur le caractère à la position p de la World
     */
    Entity* const & operator[](Point const & p) const;

    /**
     * @brief surcharge de l'opérateur [], permet d'accéder et de modifier un caractère de la World tout en modifiant également les coordonnées passées
     * en paramètres si elle "dépassent" des limites
     * 
     * @param[in] p un point contenant les coordonnées du caractère à modifier
     * @return char& référence sur le caractère à la position p de la World
     */
    Entity*& operator[](Point & p);

    /**
     * @brief surcharge de l'opérateur [], permet d'accéder uniquement en lecture à un caractère de la World tout en modifiant également les coordonnées passées
     * en paramètres si elle "dépassent" des limites
     * 
     * @param[in] p un point contenant les coordonnées du caractère à obtenir
     * @return char& référence sur le caractère à la position p de la World
     */
    Entity* const & operator[](Point & p) const;

    /**
     * @brief Méthode permettant d'obtenir les distances les plus courtes en x,y entre deux points 
     * 
     * @param[in] p1 premier point
     * @param[in] p2 deuxième point
     * @return Point x: distance entre p1.x et p2.x, y: distance entre p1.y et p2.y
     */
    Point getDistances(Point const & p1, Point const & p2) const;

    /**
     * @brief Méthode pour obtenir la direction vers une destination donnée
     * 
     * @param[in] point point de départ
     * @param[in] dest destination vers laquelle on veut aller
     * @return Point x et y qui sont soit 1, soit 0, soit -1 pour la direction
     */
    Point getDirection(Point const & point, Point const & dest) const;

    /**
     * @brief surcharge de l'opérateur <<, permettant d'afficher la World sur un flux
     * 
     * @param[in] out flux sur lequel afficher la World
     * @param[in] m World à afficher
     * @return std::ostream& flux d'entrée, permet le chaînage d'opérateurs
     */
    friend std::ostream& operator<<(std::ostream& out, World const & m);

private:
    int _width; /*!< Nombre de lignes de la World */
    int _height; /*!< Nombre de colonnes de la World */
    std::vector<std::vector<Entity*>> _world; /*!< Double tableau de caractères représentant la World */
};

#endif