/**
 * @file Resource.hpp
 * @author Mathieu Arquilliere (mathieu.arquilliere@etu.uca.fr), Jeremy Zangla (jeremy.zangla@etu.uca.fr)
 * @brief Fichier de déclaration de la classe Resource
 * @version 0.1
 * @date 2020-02-18
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#ifndef RESOURCES_HPP
#define RESOURCES_HPP

#include "Entity.hpp"
#include "../colors.hpp"

/**
 * @brief Classe Resource, héritant d'Entity
 *      Classe représentant une ressource que peut prendre les "Harvesters"
 */
class Resource : public Entity
{
public:
    /**
     * @brief Construit un nouvel objet Resource
     * 
     * @param[in] p Coordonnées où est créé l'entité
     * @param[in] c Caractère à afficher sur la map pour représenter l'entité
     */
    Resource(Point const & p, char c = 'R');

    /**
     * @brief Détruit l'objet Resource
     */
    ~Resource();

    /**
     * @brief Getter de la couleur de l'entité à afficher
     * 
     * @return std::string chaîne de caractères changeant la couleur affichée dans le terminal
     */
    std::string getColor() const override { return COLOR_BLUE; }

    /**
     * @brief Getter de Type 
     * 
     * @return ENTITY_TYPE type de l'entité
     */
    ENTITY_TYPE getType() const override { return ENTITY_TYPE::RESOURCE; }
};

#endif