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
 along with TrenchBroom.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef __TrenchBroom__EntityProperties__
#define __TrenchBroom__EntityProperties__

#include "StringUtils.h"
#include "Model/ModelTypes.h"

#include <vector>

namespace TrenchBroom {
    namespace Model {
        namespace PropertyKeys {
            extern const PropertyKey Classname;
            extern const PropertyKey Origin;
            extern const PropertyKey Wad;
            extern const PropertyKey Spawnflags;
            extern const PropertyKey EntityDefinitions;
            extern const PropertyKey Angle;
            extern const PropertyKey Angles;
            extern const PropertyKey Mangle;
            extern const PropertyKey Target;
            extern const PropertyKey Targetname;
            extern const PropertyKey Killtarget;
        }
        
        namespace PropertyValues {
            extern const PropertyValue WorldspawnClassname;
            extern const PropertyValue NoClassname;
        }

        struct EntityProperty {
            typedef std::vector<EntityProperty> List;

            PropertyKey key;
            PropertyValue value;
            
            EntityProperty(const PropertyKey& i_key, const PropertyValue& i_value) :
            key(i_key),
            value(i_value) {}
        };
        

        class EntityProperties {
        private:
            EntityProperty::List m_properties;
        public:
            const EntityProperty::List& properties() const;
            
            void addOrUpdateProperty(const PropertyKey& key, const PropertyValue& value);
            bool hasProperty(const PropertyKey& key) const;
            const PropertyValue* property(const PropertyKey& key) const;
            const PropertyValue safeProperty(const PropertyKey& key, const PropertyValue& defaultValue) const;
        private:
            EntityProperty::List::const_iterator findProperty(const PropertyKey& key) const;
            EntityProperty::List::iterator findProperty(const PropertyKey& key);
        };
    }
}

#endif /* defined(__TrenchBroom__EntityProperties__) */