/**
 * @file Map.hpp
 * @author Mathieu Arquilliere (mathieu.arquilliere@etu.uca.fr)
 * @brief Fichier de déclaration de la classe Map
 * @version 0.1
 * @date 2019-12-21
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#ifndef MAP_HPP
#define MAP_HPP

#include <vector>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include "Point.hpp"

/**
 * @brief Classe Map
 * 
 * Classe implémentant une interface d'un double tableau de caractère.
 * Cette classe permet de simplifier l'accès à l'affichage de l'environnement du système d'agents.
 * La fonctionnalité principale est qu'un objet map est un "tore" (le haut est relié au bas et la gauche à la droite)
 */
class Map
{
public:
    /**
     * @brief Construit un nouvel objet Map
     * 
     * @param[in] a nombre de "lignes" de la map
     * @param[in] b nombre de "colonnes" de la map
     */
    Map(int a, int b);

    /**
     * @brief Détruit l'objet Map
     */
    ~Map();

    /**
     * @brief Getter de _width 
     * 
     * @return int nombre de "lignes" de la map
     */
    int getWidth() const { return _width; }

    /**
     * @brief Getter de _height 
     * 
     * @return int nombre de "colonnes" de la map
     */
    int getHeight() const { return _height; }

    /**
     * @brief surcharge de l'opérateur [], permet d'accéder et de modifier un caractère de la map
     * 
     * @param[in] p un point contenant les coordonnées du caractère à modifier
     * @return char& référence sur le caractère à la position p de la map
     */
    char& operator[](Point const & p);

    /**
     * @brief surcharge de l'opérateur [], permet d'accéder uniquement en lecture à un caractère de la map
     * 
     * @param[in] p un point contenant les coordonnées du caractère à obtenir
     * @return char& référence constante sur le caractère à la position p de la map
     */
    char const & operator[](Point const & p) const;

    /**
     * @brief surcharge de l'opérateur [], permet d'accéder et de modifier un caractère de la map tout en modifiant également les coordonnées passées
     * en paramètres si elle "dépassent" des limites
     * 
     * @param[in] p un point contenant les coordonnées du caractère à modifier
     * @return char& référence sur le caractère à la position p de la map
     */
    char& operator[](Point & p);

    /**
     * @brief surcharge de l'opérateur [], permet d'accéder uniquement en lecture à un caractère de la map tout en modifiant également les coordonnées passées
     * en paramètres si elle "dépassent" des limites
     * 
     * @param[in] p un point contenant les coordonnées du caractère à obtenir
     * @return char& référence sur le caractère à la position p de la map
     */
    char const & operator[](Point & p) const;

    /**
     * @brief méthode permettant de remettre la map "vide" en remplaçant tous les caractère par '.'
     */
    void clear();

    /**
     * @brief Méthode qui permet de savoir si un point donné est dans une zone de la map
     * 
     * @param[in] point Coordonnées d'un point
     * @param[in] center Centre de la zone
     * @param[in] n Taille du voisinage
     * @return true Le point est dans la zone
     * @return false Le point n'est pas dans la zone
     */
    bool pointInNeighborhood(Point const & point, Point const & center, int n) const;

    /**
     * @brief Méthode pour obtenir la direction vers une destination donnée
     * 
     * @param[in] point point de départ
     * @param[in] dest destination vers laquelle on veut aller
     * @return Point x et y qui sont soit 1, soit 0, soit -1 pour la direction
     */
    Point getDirection(Point const & point, Point const & dest) const;

    /**
     * @brief surcharge de l'opérateur <<, permettant d'afficher la map sur un flux
     * 
     * @param[in] out flux sur lequel afficher la map
     * @param[in] m map à afficher
     * @return std::ostream& flux d'entrée, permet le chaînage d'opérateurs
     */
    friend std::ostream& operator<<(std::ostream& out, Map const & m);

private:
    int _width; /*!< Nombre de lignes de la map */
    int _height; /*!< Nombre de colonnes de la map */
    std::vector<std::vector<char>> _map; /*!< Double tableau de caractères représentant la map */
};

#endif