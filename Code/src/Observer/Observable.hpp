/**
 * @file Observable.hpp
 * @author Mathieu Arquilliere (mathieu.arquilliere@etu.uca.fr), Jeremy Zangla (jeremy.zangla@etu.uca.fr)
 * @brief Fichier de déclaration et d'implémentation de la classe Observable
 * @version 0.1
 * @date 2020-02-18
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#ifndef OBSERVABLE_HPP
#define OBSERVABLE_HPP

#include <set>
#include "IObserver.hpp"
#include "../Entities/Entity.hpp"

/**
 * @brief Classe Observable
 *      Classe fonctionnant avec l'interface IObserver pour faire un patron Observer
 *      Cette classe est faite pour être hériter par les classes qui peuvent être observées par des Observer.
 */
class Observable
{
public:
    /**
     * @brief Méthode ajoutant un Observer qui observe l'objet actuel
     * 
     * @param[in] o Objet qui possède l'interface IObserver
     */
    void addObserver(IObserver* o)
    {
        _listObserver.insert(o);
    }

    /**
     * @brief Méthode qui notifie tous les Observer d'un mouvement d'entité
     * 
     * @param[in] e entité qui bouge
     * @param[in] newPosition nouvelle position de l'entité
     */
    void notifyMove(Entity * e, Point const & newPosition)
    {
        for (auto it = _listObserver.begin(); it != _listObserver.end(); it++)
        {
            (*it)->updateMove(e, newPosition);
        }
    }

    /**
     * @brief Méthode qui notifie tous les Observer de la mort d'une entité
     * 
     * @param[in] e Entité qui meurt
     */
    void notifyKill(Entity * e)
    {
        for (auto it = _listObserver.begin(); it != _listObserver.end(); it++)
        {
            (*it)->updateKill(e);
        }
    }
    
private:
    std::set<IObserver*> _listObserver; /*!< Liste (Set) des Observer qui observe l'objet actuel */
};

#endif