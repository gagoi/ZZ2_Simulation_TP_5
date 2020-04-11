/**
 * @file World.hpp
 * @author Mathieu Arquilliere (mathieu.arquilliere@etu.uca.fr), Jeremy Zangla (jeremy.zangla@etu.uca.fr)
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

/**
 * @brief Classe World
 * 
 * Classe qui représente le monde où se situe toutes les entitées
 * Cette classe permet aux entitées d'obtenir leur environnement et de s'y déplacer
 * La fonctionnalité principale est qu'un objet World est un "tore" (le haut est relié au bas et la gauche à la droite)
 * 
 * World est un Observer d'entité afin de savoir quand une entité bouge ou meurt, la classe hérite donc de l'interface IObserver
 * World est un singleton
 */
class World : public IObserver
{
private:
    static constexpr int RANDOM_INIT = 256; /*!< seed d'initialisation pour l'aléatoire */
    static World* instance; /*!< instance de World (singleton) */

public:
    static constexpr int WORLD_WIDTH = 50; /*!< Longueur du monde 2D */
    static constexpr int WORLD_HEIGHT = 50; /*!< Hauteur du monde 2D */

    static std::mt19937 gen; /*!< générateur de nombre aléatoire Mersenne Twister */

    /**
     * @brief Getter de l'instance de World (la méthode la créee si elle n'existe pas (singleton))
     * 
     * @return World& instance de World
     */
    static World& getInstance();

    /**
     * @brief Libère la mémoire utilisée par l'instance de World
     */
    static void deleteInstance();

    /**
     * @brief Construit un nouvel objet World
     */
    World();

    /**
     * @brief Détruit l'objet World
     */
    ~World();

    /**
     * @brief Ajoute une entité au World
     * 
     * @param[in] entity Entité à ajouter
     */
    void add(Entity* entity);

    /**
     * @brief Méthode permettant d'obtenir un environnement d'une certaine taille autour d'un point
     *      Un environnement est un tableau composé de toutes les cases autour de l'origine (y compris les cases vides avec nullptr)
     * 
     * @param[in] origin point central de l'environnement voulu
     * @param[in] range taille du voisinage autour du point central
     * @return std::vector<Entity*> tableau de pointeurs d'entité représentant l'environnement voulu
     */
    std::vector<Entity*> getEnvironment(Point & origin, int range);

    /**
     * @brief Méthode qui permet d'obtenir une position aléatoire d'un environnement
     *      On choisit ce qu'on veut trouver en aléatoire dans l'environnement donné
     * 
     * @param[in] env environnement
     * @param[in] range taille du voisinage de l'environnement
     * @param[in] toFind type d'entité à trouver en aléatoire
     * @param[out] pos psoition aléatoire trouvée par la méthode
     * @return true une position à bien été trouvée
     * @return false il n'y a aucune entité de ce type dans l'environnement donné
     */
    bool findRandomPositionInEnvironment(std::vector<Entity*> env, int range, Entity::ENTITY_TYPE toFind, Point & pos);

    /**
     * @brief Méthode redéfinit hérité de l'interface IObserver qui permet de replacer une entité dans le tableau
     * 
     * @param[in] e entité qui a bougé
     * @param[in] newPosition nouvelle position de l'entité
     */
    void updateMove(Entity * e, Point const & newPosition) override;

    /**
     * @brief Méthode redéfinit hérité de l'interface IObserver qui permet de supprimer une entité dans le tableau
     * 
     * @param[in] e entité qui est morte
     */
    void updateKill(Entity * e) override;

    /**
     * @brief Méthode permettant de transformer des coordonnées pour revenir dans le World
     *      Puisque le World est un tore, les coordonnées "en dehors" correspondent à des coordonnées qui restent dans le double tableau
     * 
     * @param[in/out] p coordonnées à refactor
     */
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