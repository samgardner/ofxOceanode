//
//  ofxOceanodeNode.h
//  example-basic
//
//  Created by Eduard Frigola on 22/06/2017.
//
//

#ifndef ofxOceanodeNode_h
#define ofxOceanodeNode_h

#include "ofMain.h"

class ofxOceanodeAbstractConnection;
class ofxOceanodeNodeGui;
class ofxOceanodeNodeModel;
class ofxOceanodeContainer;

class ofxOceanodeNode {
public:
    ofxOceanodeNode(unique_ptr<ofxOceanodeNodeModel> && _nodeModel);
    ~ofxOceanodeNode();
    
    void setGui(std::unique_ptr<ofxOceanodeNodeGui>&& gui);
    
    ofxOceanodeNodeGui& getNodeGui();
    ofColor getColor();
    
    ofxOceanodeAbstractConnection* parameterConnectionPress(ofxOceanodeContainer& container, ofAbstractParameter& parameter);
    ofxOceanodeAbstractConnection* parameterConnectionRelease(ofxOceanodeContainer& container, ofAbstractParameter& parameter);
    
    ofxOceanodeAbstractConnection* createConnection(ofxOceanodeContainer& container, ofAbstractParameter& sourceParameter, ofAbstractParameter& sinkParameter);
    
    void addOutputConnection(ofxOceanodeAbstractConnection* c);
    
    void addInputConnection(ofxOceanodeAbstractConnection* c);
    
    void moveConnections(glm::vec2 moveVector);
    void setInConnectionsPositionForParameter(ofAbstractParameter &p, glm::vec2 pos);
    void setOutConnectionsPositionForParameter(ofAbstractParameter &p, glm::vec2 pos);
    
    void deleteSelf();
    
    bool loadPreset(string presetFolderPath);
    void savePreset(string presetFolderPath);
    
    void setBpm(float bpm);
    
    ofEvent<vector<ofxOceanodeAbstractConnection*>> deleteModuleAndConnections;
    ofEvent<glm::vec2> duplicateModule;
    
    void copyParametersFrom(ofParameterGroup* toCopyGroup);
    
    ofParameterGroup* getParameters();
private:
    std::unique_ptr<ofxOceanodeNodeModel> nodeModel;
    std::unique_ptr<ofxOceanodeNodeGui> nodeGui;
    
    std::vector<ofxOceanodeAbstractConnection*> inConnections;
    std::vector<ofxOceanodeAbstractConnection*> outConnections;
    
    ofEventListeners inConnectionsListeners;
    ofEventListeners outConnectionsListeners;
};

#endif /* ofxOceanodeNode_h */
