/**
 * @file Entity.hpp
 * @author Mathieu Arquilliere (mathieu.arquilliere@etu.uca.fr)
 * @brief Fichier de déclaration de la classe Entity
 * @version 0.1
 * @date 2019-12-21
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <vector>
#include "../Utils/Point.hpp"
#include "../Utils/Map.hpp"

/**
 * @brief Classe Entity, définit un objet simple existant dans l'environnement du système
 */
class Entity
{
public:
    /**
     * @brief Construit un nouvel objet Entity
     * 
     * @param[in] p Coordonnées où est créé l'entité
     * @param[in] c Caractère à afficher sur la map pour représenter l'entité
     */
    Entity(Point const & p, char c);

    /**
     * @brief Détruit l'objet Entity
     */
    virtual ~Entity();

    /**
     * @brief Getter de Position (const)
     * 
     * @return Point const& Position de l'entité dans l'environnement
     */
    Point const & getPosition() const { return _position; }

    /**
     * @brief Getter de Position
     * 
     * @return Point & Position de l'entité dans l'environnement
     */
    Point& getPosition() { return _position; }

    /**
     * @brief Getter du caractère d'affichage dans la map
     * 
     * @return char Caractère représentant l'entité
     */
    char getChar() const { return _shellChar; }

    /**
     * @brief Méthode qui "dessine" l'entité sur une map donnée
     * 
     * @param[in] map Tableau de caractères représentant le système
     */
    void draw(Map & map);

protected:
    Point _position; /*!< Position de l'entité dans le système */
    char _shellChar; /*!< Caractère représentant l'entité */
};

#endif