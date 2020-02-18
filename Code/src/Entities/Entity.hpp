/**
 * @file Entity.hpp
 * @author Mathieu Arquilliere (mathieu.arquilliere@etu.uca.fr), Jeremy Zangla (jeremy.zangla@etu.uca.fr)
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
#include "../colors.hpp"
#include "../Utils/Point.hpp"

/**
 * @brief Classe Entity, définit un objet simple existant dans l'environnement du système
 */
class Entity
{
public:
    /**
     * @brief enum définissant les différents types d'entité possible
     * 
     */
    enum class ENTITY_TYPE
    {
        ZERO,
        HARVESTER,
        HUNTER,
        BASE,
        RESOURCE,
        NONE
    };

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
     * @brief Getter de la couleur de l'entité à afficher (méthode virtuelle pure à redéfinir dans les classes filles)
     * 
     * @return std::string chaîne de caractères changeant la couleur affichée dans le terminal
     */
    virtual std::string getColor() const = 0;

    /**
     * @brief Getter de Type (méthode virtuelle pure à redéfinir dans les classes filles)
     * 
     * @return ENTITY_TYPE type de l'entité
     */
    virtual ENTITY_TYPE getType() const = 0;

    /**
     * @brief Fonction d'affichage d'une entité
     * 
     * @param[in] out flux sur lequel afficher l'entité
     * @param[in] e entité à afficher
     * @return std::ostream& le flux d'entré (retour permettant le chaînage d'opérateur de flux)
     */
    friend std::ostream& operator<<(std::ostream& out, Entity const & e);

protected:
    Point _position; /*!< Position de l'entité dans le système */
    char _shellChar; /*!< Caractère représentant l'entité */
};

#endif