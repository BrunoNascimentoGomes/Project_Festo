/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x NG!
 ***
 *** Name: Rotativo
 *** Description: Template for a Basic Function Block Type
 *** Version:
***     1.0: 2025-02-05/Bruno -  - 
 *************************************************************************/

#ifndef _ROTATIVO_H_
#define _ROTATIVO_H_

#include "basicfb.h"
#include "forte_bool.h"
#include "forte_array_at.h"


class FORTE_Rotativo: public CBasicFB {
  DECLARE_FIRMWARE_FB(FORTE_Rotativo)

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
  
  CIEC_BOOL &st_Vacuoostato() {
    return *static_cast<CIEC_BOOL*>(getDI(2));
  }
  
  CIEC_BOOL &st_Avanco() {
    return *static_cast<CIEC_BOOL*>(getDO(0));
  }
  
  CIEC_BOOL &st_Recuo() {
    return *static_cast<CIEC_BOOL*>(getDO(1));
  }
  

  void alg_Init(void);
  void alg_Update(void);

  static const TForteInt16 scm_nStateSTART = 0;
  static const TForteInt16 scm_nStateInit_ = 1;
  static const TForteInt16 scm_nStateUpdate_ = 2;
  
  void enterStateSTART(void);
  void enterStateInit_(void);
  void enterStateUpdate_(void);

  virtual void executeEvent(int pa_nEIID);

  FORTE_BASIC_FB_DATA_ARRAY(2, 3, 2, 0, 0);

public:
  FORTE_Rotativo(CStringDictionary::TStringId pa_nInstanceNameId, CResource *pa_poSrcRes) :
      CBasicFB(pa_poSrcRes, &scm_stFBInterfaceSpec, pa_nInstanceNameId, nullptr, m_anFBConnData, m_anFBVarsData) {
  };

  virtual ~FORTE_Rotativo() = default;
};

#endif // _ROTATIVO_H_


