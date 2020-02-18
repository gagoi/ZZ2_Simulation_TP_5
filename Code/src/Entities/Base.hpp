/**
 * @file Base.hpp
 * @author Mathieu Arquilliere (mathieu.arquilliere@etu.uca.fr), Jeremy Zangla (jeremy.zangla@etu.uca.fr)
 * @brief Fichier de déclaration de la classe Base
 * @version 0.1
 * @date 2019-12-26
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#ifndef BASE_HPP
#define BASE_HPP

#include <vector>
#include "../colors.hpp"
#include "Agent/Harvester.hpp"
#include "../Utils/World.hpp"
#include "Entity.hpp"

class Harvester;

/**
 * @brief Classe de l'entité Base, permettant de prendre les ressources des agents Harvester
 * et de donner naissance à des agents Harvester.
 */
class Base : public Entity
{
public:
    /**
     * @brief Construit un nouvel objet Base
     * 
     * @param[in] p Coordonnées où est créé la base 
     * @param[in] limit Nombre de ressources nécessaires afin de créer un agent Harvester
     * @param[in] c Caractère à afficher sur la map pour représenter un Harvester
     */
    Base(Point const & p, int limit, char c = 'B');

    /**
     * @brief Détruit l'objet Base
     */
    ~Base();

    /**
     * @brief Méthode permettant d'incrémenter le nombre de ressources actuelles de la base
     * 
     * @param[in] r Nombre de ressources à ajouter
     */
    bool addResources(int r);

    /**
     * @brief Méthode permettant de donner naissance à des Harvesters si les ressources sont suffisantes
     */
    void birth();

    /**
     * @brief Getter de la couleur de l'entité à afficher
     * 
     * @return std::string chaîne de caractères changeant la couleur affichée dans le terminal
     */
    std::string getColor() const override { return COLOR_CYAN; }

    /**
     * @brief Getter de Type 
     * 
     * @return ENTITY_TYPE type de l'entité
     */
    ENTITY_TYPE getType() const override { return ENTITY_TYPE::BASE; }

private:
    int         _resources; /*!< Nombre de ressources que possède actuellement la base */
    const int   _limit; /*!< Nombre de ressources nécessaires afin de créer un agent Harvester */
    bool        _hasToBirth; /*!< La base doit créer un harvester à la prochaine étape du système */
};

#endif