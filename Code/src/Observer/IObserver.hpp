/**
 * @file IObserver.hpp
 * @author Mathieu Arquilliere (mathieu.arquilliere@etu.uca.fr), Jeremy Zangla (jeremy.zangla@etu.uca.fr)
 * @brief Fichier de déclaration de l'interface IObserver
 * @version 0.1
 * @date 2020-02-18
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#ifndef IOBSERVER_HPP
#define IOBSERVER_HPP

#include "../Entities/Entity.hpp"
#include "../Utils/Point.hpp"

/**
 * @brief Interface IObserver définissant les méthode qu'un observer doit implémenter
 * 
 */
class IObserver
{
public:
    /**
     * @brief Détruit l'objet IObserver
     */
    virtual ~IObserver() {}

    /**
     * @brief Méthode virtuelle pure que doit redéfinir un observer dans le cas où une entité change de position
     * 
     * @param[in] e l'entité qui bouge
     * @param[in] newPosition nouvelle position de l'entité
     */
    virtual void updateMove(Entity* e, Point const & newPosition) = 0;

    /**
     * @brief Méthode virtuelle pure que doit redéfinir un observer dans le cas où une entité meurt
     * 
     * @param[in] e entité qui meurt
     */
    virtual void updateKill(Entity* e) = 0;
};

#endif