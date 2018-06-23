#include "PresentationMode.h"

namespace ofx {
namespace piMapper {

PresentationMode * PresentationMode::_instance = 0;

PresentationMode * PresentationMode::instance(){
	if(_instance == 0){
		_instance = new ofx::piMapper::PresentationMode();
	}
	return _instance;
}

void PresentationMode::draw(Application * app){
	ofPushStyle();
	ofSetColor(255, 255, 255, 255);
	app->getSurfaceManager()->draw();
	ofPopStyle();
}

void PresentationMode::onMousePressed(Application * app, ofMouseEventArgs & args){
		app->getCmdManager()->exec(
				new ofx::piMapper::SetApplicationModeCmd(
						app, ProjectionMappingMode::instance()));
}

void PresentationMode::onKeyPressed(Application * app, ofKeyEventArgs & args){
	switch(args.key){
	case ' ':
		for(auto const &ent: app->getMediaServer()->loadedSources)
			if(ent.second->getType() == SourceType::SOURCE_TYPE_VIDEO){
				ent.second->togglePause();
			}
			break;
	case OF_KEY_BACKSPACE:

		break;
	}
}

} // namespace piMapper
} // namespace ofx
