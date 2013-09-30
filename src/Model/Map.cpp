/*
 Copyright (C) 2010-2013 Kristian Duske
 
 This file is part of TrenchBroom.
 
 TrenchBroom is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.
 
 TrenchBroom is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with TrenchBroom. If not, see <http://www.gnu.org/licenses/>.
 */

#include "Map.h"

#include "CollectionUtils.h"

namespace TrenchBroom {
    namespace Model {
        Map::Map(const MapFormat format) :
        m_format(format),
        m_factory(m_format),
        m_worldspawn(NULL) {}
        
        Map::~Map() {
            m_worldspawn = NULL;
            VectorUtils::clearAndDelete(m_entities);
        }

        MapFormat Map::format() const {
            return m_format;
        }

        Entity* Map::createEntity() const {
            return m_factory.createEntity();
        }
        
        Brush* Map::createBrush(const BBox3& worldBounds, const BrushFaceList& faces) const {
            return m_factory.createBrush(worldBounds, faces);
        }
        
        BrushFace* Map::createFace(const Vec3& point0, const Vec3& point1, const Vec3& point2, const String& textureName) const {
            return m_factory.createFace(point0, point1, point2, textureName);
        }

        const EntityList& Map::entities() const {
            return m_entities;
        }

        void Map::addEntity(Entity* entity) {
            m_entities.push_back(entity);
        }

        void Map::removeEntity(Entity* entity) {
            VectorUtils::remove(m_entities, entity);
        }

        Entity* Map::worldspawn() const {
            if (m_worldspawn == NULL)
                m_worldspawn = findWorldspawn();
            return m_worldspawn;
        }
        
        const BrushList Map::brushes() const {
            BrushList brushes;
            EntityList::const_iterator it, end;
            for (it = m_entities.begin(), end = m_entities.end(); it != end; ++it) {
                const Entity* entity = *it;
                const Model::BrushList& entityBrushes = entity->brushes();
                brushes.insert(brushes.end(), entityBrushes.begin(), entityBrushes.end());
            }
            return brushes;
        }

        Entity* Map::findWorldspawn() const {
            EntityList::const_iterator it, end;
            for (it = m_entities.begin(), end = m_entities.end(); it != end; ++it) {
                Entity* entity = *it;
                if (entity->classname() == PropertyValues::WorldspawnClassname)
                    return entity;
            }
            return NULL;
        }
    }
}