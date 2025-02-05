/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x NG!
 ***
 *** Name: Ventosa
 *** Description: Template for a Basic Function Block Type
 *** Version:
***     1.0: 2025-02-05/Bruno -  - 
 *************************************************************************/

#ifndef _VENTOSA_H_
#define _VENTOSA_H_

#include "basicfb.h"
#include "forte_bool.h"
#include "forte_array_at.h"


class FORTE_Ventosa: public CBasicFB {
  DECLARE_FIRMWARE_FB(FORTE_Ventosa)

private:
  static const CStringDictionary::TStringId scm_anDataInputNames[];
  static const CStringDictionary::TStringId scm_anDataInputTypeIds[];
  
  static const CStringDictionary::TStringId scm_anDataOutputNames[];
  static const CStringDictionary::TStringId scm_anDataOutputTypeIds[];
  
  static const TEventID scm_nEventINITID = 0;
  static const TEventID scm_nEventREQID = 1;
  
   static const TDataIOID scm_anEIWith[];
  static const TForteInt16 scm_anEIWithIndexes[];
  static const CStringDictionary::TStringId scm_anEventInputNames[];
  
  static const TEventID scm_nEventINITOID = 0;
  static const TEventID scm_nEventCNFID = 1;
  
   static const TDataIOID scm_anEOWith[]; 
  static const TForteInt16 scm_anEOWithIndexes[];
  static const CStringDictionary::TStringId scm_anEventOutputNames[];
  

  static const SFBInterfaceSpec scm_stFBInterfaceSpec;

virtual void setInitialValues();
  CIEC_BOOL &st_Posicao_Rotativo_Recuo() {
    return *static_cast<CIEC_BOOL*>(getDI(0));
  }
  
  CIEC_BOOL &st_Posicao_Rotativo_Avanco() {
    return *static_cast<CIEC_BOOL*>(getDI(1));
  }
  
  CIEC_BOOL &st_Posicao_Atuador_Recuo() {
    return *static_cast<CIEC_BOOL*>(getDI(2));
  }
  
  CIEC_BOOL &st_Posicao_Atuador_Avanco() {
    return *static_cast<CIEC_BOOL*>(getDI(3));
  }
  
  CIEC_BOOL &st_Vacuo_On() {
    return *static_cast<CIEC_BOOL*>(getDO(0));
  }
  

  void alg_Init_(void);
  void alg_Update(void);

  static const TForteInt16 scm_nStateSTART = 0;
  static const TForteInt16 scm_nStateInit = 1;
  static const TForteInt16 scm_nStateUpdate = 2;
  
  void enterStateSTART(void);
  void enterStateInit(void);
  void enterStateUpdate(void);

  virtual void executeEvent(int pa_nEIID);

  FORTE_BASIC_FB_DATA_ARRAY(2, 4, 1, 0, 0);

public:
  FORTE_Ventosa(CStringDictionary::TStringId pa_nInstanceNameId, CResource *pa_poSrcRes) :
      CBasicFB(pa_poSrcRes, &scm_stFBInterfaceSpec, pa_nInstanceNameId, nullptr, m_anFBConnData, m_anFBVarsData) {
  };

  virtual ~FORTE_Ventosa() = default;
};

#endif // _VENTOSA_H_


