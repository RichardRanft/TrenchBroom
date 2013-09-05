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

#ifndef __TrenchBroom__ControllerFacade__
#define __TrenchBroom__ControllerFacade__

#include "TrenchBroom.h"
#include "VecMath.h"
#include "Controller/CommandProcessor.h"
#include "Controller/CommandListener.h"
#include "Model/ModelTypes.h"
#include "View/ViewTypes.h"

namespace TrenchBroom {
    namespace IO {
        class Path;
    }
    
    namespace Model {
        class Game;
    }
    
    namespace Controller {
        class CommandProcessor;
    }
    
    namespace View {
        class ControllerFacade {
        private:
            MapDocumentPtr m_document;
            Controller::CommandProcessor m_commandProcessor;
        public:
            void setDocument(MapDocumentPtr document);
            
            void addCommandListener(Controller::CommandListener::Ptr listener);
            void removeCommandListener(Controller::CommandListener::Ptr listener);

            bool newDocument(const BBox3& worldBounds, Model::GamePtr game);
            bool openDocument(const BBox3& worldBounds, Model::GamePtr game, const IO::Path& path);
            
            void beginUndoableGroup(const String& name);
            void beginOneShotGroup(const String& name);
            void closeGroup();
            void rollbackGroup();
            
            bool selectObjects(const Model::ObjectList& objects);
            bool selectObject(Model::Object* object);
            bool deselectAllAndSelectObject(Model::Object* object);
            bool deselectObject(Model::Object* object);
            bool selectFace(Model::BrushFace* face);
            bool deselectAllAndSelectFace(Model::BrushFace* face);
            bool deselectFace(Model::BrushFace* face);
            bool deselectAll();
            
            bool addObjects(const Model::ObjectList& objects);
            
            bool renameEntityProperty(const Model::EntityList& entities, const Model::PropertyKey& oldKey, const Model::PropertyKey& newKey, const bool force = false);
            bool setEntityProperty(const Model::EntityList& entities, const Model::PropertyKey& key, const Model::PropertyValue& newValue, const bool force = false);
            bool removeEntityProperty(const Model::EntityList& entities, const Model::PropertyKey& key, const bool force = false);
            
            bool setFaceXOffset(const Model::BrushFaceList& faces, const float xOffset);
            bool setFaceYOffset(const Model::BrushFaceList& faces, const float yOffset);
            bool setFaceRotation(const Model::BrushFaceList& faces, const float rotation);
            bool setFaceXScale(const Model::BrushFaceList& faces, const float xScale);
            bool setFaceYScale(const Model::BrushFaceList& faces, const float yScale);
        };
    }
}

#endif /* defined(__TrenchBroom__ControllerFacade__) */