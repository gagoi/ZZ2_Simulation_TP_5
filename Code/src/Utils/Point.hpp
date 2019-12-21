/**
 * @file Point.hpp
 * @author Mathieu Arquilliere (mathieu.arquilliere@etu.uca.fr)
 * @brief Fichier de la structure utilitaire Point
 * @version 0.1
 * @date 2019-12-21
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#ifndef POINT_HPP
#define POINT_HPP

/**
 * @brief Classe permettant de simplifier les coordonnées d'un environnement 2D
 * Cette classe surcharge les opérateurs de base permettant de manipuler des Points facilement.
 * Elle surcharge l'opérateur :
 *  - d'affectation
 *  - d'égalité
 *  - d'inégalité
 *  - d'incrémentation (+=)
 *  - de décrémentation (-=)
 *  - de somme
 *  - de différence
 */
struct Point
{
    int x; /*!< Ordonné (ligne) */
    int y; /*!< Abscisse (colonne) */

    /**
     * @brief Construit un nouvel objet Point
     * Par défaut, x et y sont mis à 0
     */
    Point() : x(0), y(0) {}

    /**
     * @brief Construit un nouvel objet Point
     * 
     * @param[in] a valeur à donner à x
     * @param[in] b valeur à donner à y
     */
    Point(int a, int b) : x(a), y(b) {}

    Point& operator=(Point const & p) { x = p.x; y = p.y; return *this; }
    bool operator==(Point const & p) { return x == p.x && y == p.y; }
    bool operator!=(Point const & p) { return !(*this != p); }
    Point& operator+=(Point const & p) { x += p.x; y += p.y; return *this; }
    Point operator+(Point const & p) { return Point(x + p.x, y + p.y); }
    Point& operator-=(Point const & p) { x -= p.x; y -= p.y; return *this; }
    Point operator-(Point const & p) { return Point(x - p.x, y - p.y); }
};


#endif