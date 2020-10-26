#
# usage:
#   mkdir _build
#   cd _build
#   cmake -DCMAKE_INSTALL_PREFIX:PATH=C:/online_update -DPREPOST_GUI:PATH=C:/prepost-gui ..

cmake_minimum_required(VERSION 3.1)


if(CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
  set(CMAKE_INSTALL_PREFIX c:/online_update CACHE PATH "Top level directory of online_update workspace" FORCE)
endif()

if(NOT PREPOST_GUI)
  set(PREPOST_GUI c:/prepost-gui)
endif()

# gridexporter_gridlandxmlexporter
set(gridexporter_gridlandxmlexporter
  ${PREPOST_GUI}/libdlls/Release/gridlandxmlexporter.dll
  ${PREPOST_GUI}/plugins/gridexporter/gridlandxmlexporter/languages/gridlandxmlexporter_ar_EG.qm
  ${PREPOST_GUI}/plugins/gridexporter/gridlandxmlexporter/languages/gridlandxmlexporter_bg_BG.qm
  ${PREPOST_GUI}/plugins/gridexporter/gridlandxmlexporter/languages/gridlandxmlexporter_bs_BA.qm
  ${PREPOST_GUI}/plugins/gridexporter/gridlandxmlexporter/languages/gridlandxmlexporter_ca_ES.qm
  ${PREPOST_GUI}/plugins/gridexporter/gridlandxmlexporter/languages/gridlandxmlexporter_cs_CZ.qm
  ${PREPOST_GUI}/plugins/gridexporter/gridlandxmlexporter/languages/gridlandxmlexporter_da_DK.qm
  ${PREPOST_GUI}/plugins/gridexporter/gridlandxmlexporter/languages/gridlandxmlexporter_de_DE.qm
  ${PREPOST_GUI}/plugins/gridexporter/gridlandxmlexporter/languages/gridlandxmlexporter_el_GR.qm
  ${PREPOST_GUI}/plugins/gridexporter/gridlandxmlexporter/languages/gridlandxmlexporter_es_ES.qm
  ${PREPOST_GUI}/plugins/gridexporter/gridlandxmlexporter/languages/gridlandxmlexporter_et_EE.qm
  ${PREPOST_GUI}/plugins/gridexporter/gridlandxmlexporter/languages/gridlandxmlexporter_eu_ES.qm
  ${PREPOST_GUI}/plugins/gridexporter/gridlandxmlexporter/languages/gridlandxmlexporter_fi_FI.qm
  ${PREPOST_GUI}/plugins/gridexporter/gridlandxmlexporter/languages/gridlandxmlexporter_fr_FR.qm
  ${PREPOST_GUI}/plugins/gridexporter/gridlandxmlexporter/languages/gridlandxmlexporter_gl_ES.qm
  ${PREPOST_GUI}/plugins/gridexporter/gridlandxmlexporter/languages/gridlandxmlexporter_hi_IN.qm
  ${PREPOST_GUI}/plugins/gridexporter/gridlandxmlexporter/languages/gridlandxmlexporter_hu_HU.qm
  ${PREPOST_GUI}/plugins/gridexporter/gridlandxmlexporter/languages/gridlandxmlexporter_id_ID.qm
  ${PREPOST_GUI}/plugins/gridexporter/gridlandxmlexporter/languages/gridlandxmlexporter_is_IS.qm
  ${PREPOST_GUI}/plugins/gridexporter/gridlandxmlexporter/languages/gridlandxmlexporter_it_IT.qm
  ${PREPOST_GUI}/plugins/gridexporter/gridlandxmlexporter/languages/gridlandxmlexporter_ja_JP.qm
  ${PREPOST_GUI}/plugins/gridexporter/gridlandxmlexporter/languages/gridlandxmlexporter_ko_KR.qm
  ${PREPOST_GUI}/plugins/gridexporter/gridlandxmlexporter/languages/gridlandxmlexporter_ky_KG.qm
  ${PREPOST_GUI}/plugins/gridexporter/gridlandxmlexporter/languages/gridlandxmlexporter_lt_LT.qm
  ${PREPOST_GUI}/plugins/gridexporter/gridlandxmlexporter/languages/gridlandxmlexporter_lv_LV.qm
  ${PREPOST_GUI}/plugins/gridexporter/gridlandxmlexporter/languages/gridlandxmlexporter_nb_NO.qm
  ${PREPOST_GUI}/plugins/gridexporter/gridlandxmlexporter/languages/gridlandxmlexporter_nl_NL.qm
  ${PREPOST_GUI}/plugins/gridexporter/gridlandxmlexporter/languages/gridlandxmlexporter_pl_PL.qm
  ${PREPOST_GUI}/plugins/gridexporter/gridlandxmlexporter/languages/gridlandxmlexporter_pt_BR.qm
  ${PREPOST_GUI}/plugins/gridexporter/gridlandxmlexporter/languages/gridlandxmlexporter_pt_PT.qm
  ${PREPOST_GUI}/plugins/gridexporter/gridlandxmlexporter/languages/gridlandxmlexporter_ro_RO.qm
  ${PREPOST_GUI}/plugins/gridexporter/gridlandxmlexporter/languages/gridlandxmlexporter_ru_RU.qm
  ${PREPOST_GUI}/plugins/gridexporter/gridlandxmlexporter/languages/gridlandxmlexporter_sl_SI.qm
  ${PREPOST_GUI}/plugins/gridexporter/gridlandxmlexporter/languages/gridlandxmlexporter_sv_SE.qm
  ${PREPOST_GUI}/plugins/gridexporter/gridlandxmlexporter/languages/gridlandxmlexporter_th_TH.qm
  ${PREPOST_GUI}/plugins/gridexporter/gridlandxmlexporter/languages/gridlandxmlexporter_tr_TR.qm
  ${PREPOST_GUI}/plugins/gridexporter/gridlandxmlexporter/languages/gridlandxmlexporter_uk_UA.qm
  ${PREPOST_GUI}/plugins/gridexporter/gridlandxmlexporter/languages/gridlandxmlexporter_vi_VN.qm
  ${PREPOST_GUI}/plugins/gridexporter/gridlandxmlexporter/languages/gridlandxmlexporter_zh_CN.qm
  ${PREPOST_GUI}/plugins/gridexporter/gridlandxmlexporter/languages/gridlandxmlexporter_zh_TW.qm
)
# install(FILES ${gridexporter_gridlandxmlexporter}
#   DESTINATION ${CMAKE_INSTALL_PREFIX}/${SRC_FOLDER}/packages/gridexporter_plugin.gridlandxmlexporter
# )

# gridexporter_structured2dgridnayscsvexporter
set(gridexporter_structured2dgridnayscsvexporter
  ${PREPOST_GUI}/libdlls/Release/structured2dgridnayscsvexporter.dll
  ${PREPOST_GUI}/plugins/gridexporter/structured2dgridnayscsvexporter/languages/structured2dgridnayscsvexporter_ar_EG.qm
  ${PREPOST_GUI}/plugins/gridexporter/structured2dgridnayscsvexporter/languages/structured2dgridnayscsvexporter_bg_BG.qm
  ${PREPOST_GUI}/plugins/gridexporter/structured2dgridnayscsvexporter/languages/structured2dgridnayscsvexporter_bs_BA.qm
  ${PREPOST_GUI}/plugins/gridexporter/structured2dgridnayscsvexporter/languages/structured2dgridnayscsvexporter_ca_ES.qm
  ${PREPOST_GUI}/plugins/gridexporter/structured2dgridnayscsvexporter/languages/structured2dgridnayscsvexporter_cs_CZ.qm
  ${PREPOST_GUI}/plugins/gridexporter/structured2dgridnayscsvexporter/languages/structured2dgridnayscsvexporter_da_DK.qm
  ${PREPOST_GUI}/plugins/gridexporter/structured2dgridnayscsvexporter/languages/structured2dgridnayscsvexporter_de_DE.qm
  ${PREPOST_GUI}/plugins/gridexporter/structured2dgridnayscsvexporter/languages/structured2dgridnayscsvexporter_el_GR.qm
  ${PREPOST_GUI}/plugins/gridexporter/structured2dgridnayscsvexporter/languages/structured2dgridnayscsvexporter_es_ES.qm
  ${PREPOST_GUI}/plugins/gridexporter/structured2dgridnayscsvexporter/languages/structured2dgridnayscsvexporter_et_EE.qm
  ${PREPOST_GUI}/plugins/gridexporter/structured2dgridnayscsvexporter/languages/structured2dgridnayscsvexporter_eu_ES.qm
  ${PREPOST_GUI}/plugins/gridexporter/structured2dgridnayscsvexporter/languages/structured2dgridnayscsvexporter_fi_FI.qm
  ${PREPOST_GUI}/plugins/gridexporter/structured2dgridnayscsvexporter/languages/structured2dgridnayscsvexporter_fr_FR.qm
  ${PREPOST_GUI}/plugins/gridexporter/structured2dgridnayscsvexporter/languages/structured2dgridnayscsvexporter_gl_ES.qm
  ${PREPOST_GUI}/plugins/gridexporter/structured2dgridnayscsvexporter/languages/structured2dgridnayscsvexporter_hi_IN.qm
  ${PREPOST_GUI}/plugins/gridexporter/structured2dgridnayscsvexporter/languages/structured2dgridnayscsvexporter_hu_HU.qm
  ${PREPOST_GUI}/plugins/gridexporter/structured2dgridnayscsvexporter/languages/structured2dgridnayscsvexporter_id_ID.qm
  ${PREPOST_GUI}/plugins/gridexporter/structured2dgridnayscsvexporter/languages/structured2dgridnayscsvexporter_is_IS.qm
  ${PREPOST_GUI}/plugins/gridexporter/structured2dgridnayscsvexporter/languages/structured2dgridnayscsvexporter_it_IT.qm
  ${PREPOST_GUI}/plugins/gridexporter/structured2dgridnayscsvexporter/languages/structured2dgridnayscsvexporter_ja_JP.qm
  )
#install(FILES ${GRID_EXPORTER.structured2dgridnayscsv}
#  DESTINATION ${CMAKE_INSTALL_PREFIX}/dev_src/packages/gridexporter_plugin.structured2dgridnayscsv/data
#  )

# gridexporter_structured2dgridnaysgridexporter
set(gridexporter_structured2dgridnaysgridexporter
  ${PREPOST_GUI}/libdlls/Release/structured2dgridnaysgridexporter.dll
  ${PREPOST_GUI}/plugins/gridexporter/structured2dgridnaysgridexporter/languages/structured2dgridnaysgridexporter_ar_EG.qm
  ${PREPOST_GUI}/plugins/gridexporter/structured2dgridnaysgridexporter/languages/structured2dgridnaysgridexporter_bg_BG.qm
  ${PREPOST_GUI}/plugins/gridexporter/structured2dgridnaysgridexporter/languages/structured2dgridnaysgridexporter_bs_BA.qm
  ${PREPOST_GUI}/plugins/gridexporter/structured2dgridnaysgridexporter/languages/structured2dgridnaysgridexporter_ca_ES.qm
  ${PREPOST_GUI}/plugins/gridexporter/structured2dgridnaysgridexporter/languages/structured2dgridnaysgridexporter_cs_CZ.qm
  ${PREPOST_GUI}/plugins/gridexporter/structured2dgridnaysgridexporter/languages/structured2dgridnaysgridexporter_da_DK.qm
  ${PREPOST_GUI}/plugins/gridexporter/structured2dgridnaysgridexporter/languages/structured2dgridnaysgridexporter_de_DE.qm
  ${PREPOST_GUI}/plugins/gridexporter/structured2dgridnaysgridexporter/languages/structured2dgridnaysgridexporter_el_GR.qm
  ${PREPOST_GUI}/plugins/gridexporter/structured2dgridnaysgridexporter/languages/structured2dgridnaysgridexporter_es_ES.qm
  ${PREPOST_GUI}/plugins/gridexporter/structured2dgridnaysgridexporter/languages/structured2dgridnaysgridexporter_et_EE.qm
  ${PREPOST_GUI}/plugins/gridexporter/structured2dgridnaysgridexporter/languages/structured2dgridnaysgridexporter_eu_ES.qm
  ${PREPOST_GUI}/plugins/gridexporter/structured2dgridnaysgridexporter/languages/structured2dgridnaysgridexporter_fi_FI.qm
  ${PREPOST_GUI}/plugins/gridexporter/structured2dgridnaysgridexporter/languages/structured2dgridnaysgridexporter_fr_FR.qm
  ${PREPOST_GUI}/plugins/gridexporter/structured2dgridnaysgridexporter/languages/structured2dgridnaysgridexporter_gl_ES.qm
  ${PREPOST_GUI}/plugins/gridexporter/structured2dgridnaysgridexporter/languages/structured2dgridnaysgridexporter_hi_IN.qm
  ${PREPOST_GUI}/plugins/gridexporter/structured2dgridnaysgridexporter/languages/structured2dgridnaysgridexporter_hu_HU.qm
  ${PREPOST_GUI}/plugins/gridexporter/structured2dgridnaysgridexporter/languages/structured2dgridnaysgridexporter_id_ID.qm
  ${PREPOST_GUI}/plugins/gridexporter/structured2dgridnaysgridexporter/languages/structured2dgridnaysgridexporter_is_IS.qm
  ${PREPOST_GUI}/plugins/gridexporter/structured2dgridnaysgridexporter/languages/structured2dgridnaysgridexporter_it_IT.qm
  ${PREPOST_GUI}/plugins/gridexporter/structured2dgridnaysgridexporter/languages/structured2dgridnaysgridexporter_ja_JP.qm
  )
#install(FILES ${GRID_EXPORTER.structured2dgridnaysgrid}
#  DESTINATION ${CMAKE_INSTALL_PREFIX}/dev_src/packages/gridexporter_plugin.structured2dgridnaysgrid/data
#  )

# gridexporter_structured2dgridvtkexporter
set(gridexporter_structured2dgridvtkexporter
  ${PREPOST_GUI}/libdlls/Release/structured2dgridvtkexporter.dll
  ${PREPOST_GUI}/plugins/gridexporter/structured2dgridvtkexporter/languages/structured2dgridvtkexporter_ar_EG.qm
  ${PREPOST_GUI}/plugins/gridexporter/structured2dgridvtkexporter/languages/structured2dgridvtkexporter_bg_BG.qm
  ${PREPOST_GUI}/plugins/gridexporter/structured2dgridvtkexporter/languages/structured2dgridvtkexporter_bs_BA.qm
  ${PREPOST_GUI}/plugins/gridexporter/structured2dgridvtkexporter/languages/structured2dgridvtkexporter_ca_ES.qm
  ${PREPOST_GUI}/plugins/gridexporter/structured2dgridvtkexporter/languages/structured2dgridvtkexporter_cs_CZ.qm
  ${PREPOST_GUI}/plugins/gridexporter/structured2dgridvtkexporter/languages/structured2dgridvtkexporter_da_DK.qm
  ${PREPOST_GUI}/plugins/gridexporter/structured2dgridvtkexporter/languages/structured2dgridvtkexporter_de_DE.qm
  ${PREPOST_GUI}/plugins/gridexporter/structured2dgridvtkexporter/languages/structured2dgridvtkexporter_el_GR.qm
  ${PREPOST_GUI}/plugins/gridexporter/structured2dgridvtkexporter/languages/structured2dgridvtkexporter_es_ES.qm
  ${PREPOST_GUI}/plugins/gridexporter/structured2dgridvtkexporter/languages/structured2dgridvtkexporter_et_EE.qm
  ${PREPOST_GUI}/plugins/gridexporter/structured2dgridvtkexporter/languages/structured2dgridvtkexporter_eu_ES.qm
  ${PREPOST_GUI}/plugins/gridexporter/structured2dgridvtkexporter/languages/structured2dgridvtkexporter_fi_FI.qm
  ${PREPOST_GUI}/plugins/gridexporter/structured2dgridvtkexporter/languages/structured2dgridvtkexporter_fr_FR.qm
  ${PREPOST_GUI}/plugins/gridexporter/structured2dgridvtkexporter/languages/structured2dgridvtkexporter_gl_ES.qm
  ${PREPOST_GUI}/plugins/gridexporter/structured2dgridvtkexporter/languages/structured2dgridvtkexporter_hi_IN.qm
  ${PREPOST_GUI}/plugins/gridexporter/structured2dgridvtkexporter/languages/structured2dgridvtkexporter_hu_HU.qm
  ${PREPOST_GUI}/plugins/gridexporter/structured2dgridvtkexporter/languages/structured2dgridvtkexporter_id_ID.qm
  ${PREPOST_GUI}/plugins/gridexporter/structured2dgridvtkexporter/languages/structured2dgridvtkexporter_is_IS.qm
  ${PREPOST_GUI}/plugins/gridexporter/structured2dgridvtkexporter/languages/structured2dgridvtkexporter_it_IT.qm
  ${PREPOST_GUI}/plugins/gridexporter/structured2dgridvtkexporter/languages/structured2dgridvtkexporter_ja_JP.qm
  )
#install(FILES ${GRID_EXPORTER.structured2dgridvtk}
#  DESTINATION ${CMAKE_INSTALL_PREFIX}/dev_src/packages/gridexporter_plugin.structured2dgridvtk/data
#  )

# gridexporter_unstructured2dgridvtkexporter
set(gridexporter_unstructured2dgridvtkexporter
  ${PREPOST_GUI}/libdlls/Release/unstructured2dgridvtkexporter.dll
  ${PREPOST_GUI}/plugins/gridexporter/unstructured2dgridvtkexporter/languages/unstructured2dgridvtkexporter_ar_EG.qm
  ${PREPOST_GUI}/plugins/gridexporter/unstructured2dgridvtkexporter/languages/unstructured2dgridvtkexporter_bg_BG.qm
  ${PREPOST_GUI}/plugins/gridexporter/unstructured2dgridvtkexporter/languages/unstructured2dgridvtkexporter_bs_BA.qm
  ${PREPOST_GUI}/plugins/gridexporter/unstructured2dgridvtkexporter/languages/unstructured2dgridvtkexporter_ca_ES.qm
  ${PREPOST_GUI}/plugins/gridexporter/unstructured2dgridvtkexporter/languages/unstructured2dgridvtkexporter_cs_CZ.qm
  ${PREPOST_GUI}/plugins/gridexporter/unstructured2dgridvtkexporter/languages/unstructured2dgridvtkexporter_da_DK.qm
  ${PREPOST_GUI}/plugins/gridexporter/unstructured2dgridvtkexporter/languages/unstructured2dgridvtkexporter_de_DE.qm
  ${PREPOST_GUI}/plugins/gridexporter/unstructured2dgridvtkexporter/languages/unstructured2dgridvtkexporter_el_GR.qm
  ${PREPOST_GUI}/plugins/gridexporter/unstructured2dgridvtkexporter/languages/unstructured2dgridvtkexporter_es_ES.qm
  ${PREPOST_GUI}/plugins/gridexporter/unstructured2dgridvtkexporter/languages/unstructured2dgridvtkexporter_et_EE.qm
  ${PREPOST_GUI}/plugins/gridexporter/unstructured2dgridvtkexporter/languages/unstructured2dgridvtkexporter_eu_ES.qm
  ${PREPOST_GUI}/plugins/gridexporter/unstructured2dgridvtkexporter/languages/unstructured2dgridvtkexporter_fi_FI.qm
  ${PREPOST_GUI}/plugins/gridexporter/unstructured2dgridvtkexporter/languages/unstructured2dgridvtkexporter_fr_FR.qm
  ${PREPOST_GUI}/plugins/gridexporter/unstructured2dgridvtkexporter/languages/unstructured2dgridvtkexporter_gl_ES.qm
  ${PREPOST_GUI}/plugins/gridexporter/unstructured2dgridvtkexporter/languages/unstructured2dgridvtkexporter_hi_IN.qm
  ${PREPOST_GUI}/plugins/gridexporter/unstructured2dgridvtkexporter/languages/unstructured2dgridvtkexporter_hu_HU.qm
  ${PREPOST_GUI}/plugins/gridexporter/unstructured2dgridvtkexporter/languages/unstructured2dgridvtkexporter_id_ID.qm
  ${PREPOST_GUI}/plugins/gridexporter/unstructured2dgridvtkexporter/languages/unstructured2dgridvtkexporter_is_IS.qm
  ${PREPOST_GUI}/plugins/gridexporter/unstructured2dgridvtkexporter/languages/unstructured2dgridvtkexporter_it_IT.qm
  ${PREPOST_GUI}/plugins/gridexporter/unstructured2dgridvtkexporter/languages/unstructured2dgridvtkexporter_ja_JP.qm
  )
#install(FILES ${GRID_EXPORTER.unstructured2dgridvtk}
#  DESTINATION ${CMAKE_INSTALL_PREFIX}/dev_src/packages/gridexporter_plugin.unstructured2dgridvtk/data
#  )

# gridimporter_structured2dgridgdalimporter
set(gridimporter_structured2dgridgdalimporter
  ${PREPOST_GUI}/libdlls/Release/structured2dgridgdalimporter.dll
  ${PREPOST_GUI}/plugins/gridimporter/structured2dgridgdalimporter/languages/structured2dgridgdalimporter_ar_EG.qm
  ${PREPOST_GUI}/plugins/gridimporter/structured2dgridgdalimporter/languages/structured2dgridgdalimporter_bg_BG.qm
  ${PREPOST_GUI}/plugins/gridimporter/structured2dgridgdalimporter/languages/structured2dgridgdalimporter_bs_BA.qm
  ${PREPOST_GUI}/plugins/gridimporter/structured2dgridgdalimporter/languages/structured2dgridgdalimporter_ca_ES.qm
  ${PREPOST_GUI}/plugins/gridimporter/structured2dgridgdalimporter/languages/structured2dgridgdalimporter_cs_CZ.qm
  ${PREPOST_GUI}/plugins/gridimporter/structured2dgridgdalimporter/languages/structured2dgridgdalimporter_da_DK.qm
  ${PREPOST_GUI}/plugins/gridimporter/structured2dgridgdalimporter/languages/structured2dgridgdalimporter_de_DE.qm
  ${PREPOST_GUI}/plugins/gridimporter/structured2dgridgdalimporter/languages/structured2dgridgdalimporter_el_GR.qm
  ${PREPOST_GUI}/plugins/gridimporter/structured2dgridgdalimporter/languages/structured2dgridgdalimporter_es_ES.qm
  ${PREPOST_GUI}/plugins/gridimporter/structured2dgridgdalimporter/languages/structured2dgridgdalimporter_et_EE.qm
  ${PREPOST_GUI}/plugins/gridimporter/structured2dgridgdalimporter/languages/structured2dgridgdalimporter_eu_ES.qm
  ${PREPOST_GUI}/plugins/gridimporter/structured2dgridgdalimporter/languages/structured2dgridgdalimporter_fi_FI.qm
  ${PREPOST_GUI}/plugins/gridimporter/structured2dgridgdalimporter/languages/structured2dgridgdalimporter_fr_FR.qm
  ${PREPOST_GUI}/plugins/gridimporter/structured2dgridgdalimporter/languages/structured2dgridgdalimporter_gl_ES.qm
  ${PREPOST_GUI}/plugins/gridimporter/structured2dgridgdalimporter/languages/structured2dgridgdalimporter_hi_IN.qm
  ${PREPOST_GUI}/plugins/gridimporter/structured2dgridgdalimporter/languages/structured2dgridgdalimporter_hu_HU.qm
  ${PREPOST_GUI}/plugins/gridimporter/structured2dgridgdalimporter/languages/structured2dgridgdalimporter_id_ID.qm
  ${PREPOST_GUI}/plugins/gridimporter/structured2dgridgdalimporter/languages/structured2dgridgdalimporter_is_IS.qm
  ${PREPOST_GUI}/plugins/gridimporter/structured2dgridgdalimporter/languages/structured2dgridgdalimporter_it_IT.qm
  ${PREPOST_GUI}/plugins/gridimporter/structured2dgridgdalimporter/languages/structured2dgridgdalimporter_ja_JP.qm
  ${PREPOST_GUI}/plugins/gridimporter/structured2dgridgdalimporter/languages/structured2dgridgdalimporter_ko_KR.qm
  ${PREPOST_GUI}/plugins/gridimporter/structured2dgridgdalimporter/languages/structured2dgridgdalimporter_ky_KG.qm
  ${PREPOST_GUI}/plugins/gridimporter/structured2dgridgdalimporter/languages/structured2dgridgdalimporter_lt_LT.qm
  ${PREPOST_GUI}/plugins/gridimporter/structured2dgridgdalimporter/languages/structured2dgridgdalimporter_lv_LV.qm
  ${PREPOST_GUI}/plugins/gridimporter/structured2dgridgdalimporter/languages/structured2dgridgdalimporter_nb_NO.qm
  ${PREPOST_GUI}/plugins/gridimporter/structured2dgridgdalimporter/languages/structured2dgridgdalimporter_nl_NL.qm
  ${PREPOST_GUI}/plugins/gridimporter/structured2dgridgdalimporter/languages/structured2dgridgdalimporter_pl_PL.qm
  ${PREPOST_GUI}/plugins/gridimporter/structured2dgridgdalimporter/languages/structured2dgridgdalimporter_pt_BR.qm
  ${PREPOST_GUI}/plugins/gridimporter/structured2dgridgdalimporter/languages/structured2dgridgdalimporter_pt_PT.qm
  ${PREPOST_GUI}/plugins/gridimporter/structured2dgridgdalimporter/languages/structured2dgridgdalimporter_ro_RO.qm
  ${PREPOST_GUI}/plugins/gridimporter/structured2dgridgdalimporter/languages/structured2dgridgdalimporter_ru_RU.qm
  ${PREPOST_GUI}/plugins/gridimporter/structured2dgridgdalimporter/languages/structured2dgridgdalimporter_sl_SI.qm
  ${PREPOST_GUI}/plugins/gridimporter/structured2dgridgdalimporter/languages/structured2dgridgdalimporter_sv_SE.qm
  ${PREPOST_GUI}/plugins/gridimporter/structured2dgridgdalimporter/languages/structured2dgridgdalimporter_th_TH.qm
  ${PREPOST_GUI}/plugins/gridimporter/structured2dgridgdalimporter/languages/structured2dgridgdalimporter_tr_TR.qm
  ${PREPOST_GUI}/plugins/gridimporter/structured2dgridgdalimporter/languages/structured2dgridgdalimporter_uk_UA.qm
  ${PREPOST_GUI}/plugins/gridimporter/structured2dgridgdalimporter/languages/structured2dgridgdalimporter_vi_VN.qm
  ${PREPOST_GUI}/plugins/gridimporter/structured2dgridgdalimporter/languages/structured2dgridgdalimporter_zh_CN.qm
  ${PREPOST_GUI}/plugins/gridimporter/structured2dgridgdalimporter/languages/structured2dgridgdalimporter_zh_TW.qm
)
# install(FILES ${gridimporter_structured2dgridgdalimporter}
#   DESTINATION ${CMAKE_INSTALL_PREFIX}/${SRC_FOLDER}/packages/gridimporter_plugin.structured2dgridgdalimporter
# )

# gridimporter_structured2dgridnayscsvimporter
set(gridimporter_structured2dgridnayscsvimporter
  ${PREPOST_GUI}/libdlls/Release/structured2dgridnayscsvimporter.dll
  ${PREPOST_GUI}/plugins/gridimporter/structured2dgridnayscsvimporter/languages/structured2dgridnayscsvimporter_ar_EG.qm
  ${PREPOST_GUI}/plugins/gridimporter/structured2dgridnayscsvimporter/languages/structured2dgridnayscsvimporter_bg_BG.qm
  ${PREPOST_GUI}/plugins/gridimporter/structured2dgridnayscsvimporter/languages/structured2dgridnayscsvimporter_bs_BA.qm
  ${PREPOST_GUI}/plugins/gridimporter/structured2dgridnayscsvimporter/languages/structured2dgridnayscsvimporter_ca_ES.qm
  ${PREPOST_GUI}/plugins/gridimporter/structured2dgridnayscsvimporter/languages/structured2dgridnayscsvimporter_cs_CZ.qm
  ${PREPOST_GUI}/plugins/gridimporter/structured2dgridnayscsvimporter/languages/structured2dgridnayscsvimporter_da_DK.qm
  ${PREPOST_GUI}/plugins/gridimporter/structured2dgridnayscsvimporter/languages/structured2dgridnayscsvimporter_de_DE.qm
  ${PREPOST_GUI}/plugins/gridimporter/structured2dgridnayscsvimporter/languages/structured2dgridnayscsvimporter_el_GR.qm
  ${PREPOST_GUI}/plugins/gridimporter/structured2dgridnayscsvimporter/languages/structured2dgridnayscsvimporter_es_ES.qm
  ${PREPOST_GUI}/plugins/gridimporter/structured2dgridnayscsvimporter/languages/structured2dgridnayscsvimporter_et_EE.qm
  ${PREPOST_GUI}/plugins/gridimporter/structured2dgridnayscsvimporter/languages/structured2dgridnayscsvimporter_eu_ES.qm
  ${PREPOST_GUI}/plugins/gridimporter/structured2dgridnayscsvimporter/languages/structured2dgridnayscsvimporter_fi_FI.qm
  ${PREPOST_GUI}/plugins/gridimporter/structured2dgridnayscsvimporter/languages/structured2dgridnayscsvimporter_fr_FR.qm
  ${PREPOST_GUI}/plugins/gridimporter/structured2dgridnayscsvimporter/languages/structured2dgridnayscsvimporter_gl_ES.qm
  ${PREPOST_GUI}/plugins/gridimporter/structured2dgridnayscsvimporter/languages/structured2dgridnayscsvimporter_hi_IN.qm
  ${PREPOST_GUI}/plugins/gridimporter/structured2dgridnayscsvimporter/languages/structured2dgridnayscsvimporter_hu_HU.qm
  ${PREPOST_GUI}/plugins/gridimporter/structured2dgridnayscsvimporter/languages/structured2dgridnayscsvimporter_id_ID.qm
  ${PREPOST_GUI}/plugins/gridimporter/structured2dgridnayscsvimporter/languages/structured2dgridnayscsvimporter_is_IS.qm
  ${PREPOST_GUI}/plugins/gridimporter/structured2dgridnayscsvimporter/languages/structured2dgridnayscsvimporter_it_IT.qm
  ${PREPOST_GUI}/plugins/gridimporter/structured2dgridnayscsvimporter/languages/structured2dgridnayscsvimporter_ja_JP.qm
  )
#install(FILES ${GRID_IMPORTER.structured2dgridnayscsv}
#  DESTINATION ${CMAKE_INSTALL_PREFIX}/dev_src/packages/gridimporter_plugin.structured2dgridnayscsv/data
#  )

# gridimporter_structured2dgridnaysgridimporter
set(gridimporter_structured2dgridnaysgridimporter
  ${PREPOST_GUI}/libdlls/Release/structured2dgridnaysgridimporter.dll
  ${PREPOST_GUI}/plugins/gridimporter/structured2dgridnaysgridimporter/languages/structured2dgridnaysgridimporter_ar_EG.qm
  ${PREPOST_GUI}/plugins/gridimporter/structured2dgridnaysgridimporter/languages/structured2dgridnaysgridimporter_bg_BG.qm
  ${PREPOST_GUI}/plugins/gridimporter/structured2dgridnaysgridimporter/languages/structured2dgridnaysgridimporter_bs_BA.qm
  ${PREPOST_GUI}/plugins/gridimporter/structured2dgridnaysgridimporter/languages/structured2dgridnaysgridimporter_ca_ES.qm
  ${PREPOST_GUI}/plugins/gridimporter/structured2dgridnaysgridimporter/languages/structured2dgridnaysgridimporter_cs_CZ.qm
  ${PREPOST_GUI}/plugins/gridimporter/structured2dgridnaysgridimporter/languages/structured2dgridnaysgridimporter_da_DK.qm
  ${PREPOST_GUI}/plugins/gridimporter/structured2dgridnaysgridimporter/languages/structured2dgridnaysgridimporter_de_DE.qm
  ${PREPOST_GUI}/plugins/gridimporter/structured2dgridnaysgridimporter/languages/structured2dgridnaysgridimporter_el_GR.qm
  ${PREPOST_GUI}/plugins/gridimporter/structured2dgridnaysgridimporter/languages/structured2dgridnaysgridimporter_es_ES.qm
  ${PREPOST_GUI}/plugins/gridimporter/structured2dgridnaysgridimporter/languages/structured2dgridnaysgridimporter_et_EE.qm
  ${PREPOST_GUI}/plugins/gridimporter/structured2dgridnaysgridimporter/languages/structured2dgridnaysgridimporter_eu_ES.qm
  ${PREPOST_GUI}/plugins/gridimporter/structured2dgridnaysgridimporter/languages/structured2dgridnaysgridimporter_fi_FI.qm
  ${PREPOST_GUI}/plugins/gridimporter/structured2dgridnaysgridimporter/languages/structured2dgridnaysgridimporter_fr_FR.qm
  ${PREPOST_GUI}/plugins/gridimporter/structured2dgridnaysgridimporter/languages/structured2dgridnaysgridimporter_gl_ES.qm
  ${PREPOST_GUI}/plugins/gridimporter/structured2dgridnaysgridimporter/languages/structured2dgridnaysgridimporter_hi_IN.qm
  ${PREPOST_GUI}/plugins/gridimporter/structured2dgridnaysgridimporter/languages/structured2dgridnaysgridimporter_hu_HU.qm
  ${PREPOST_GUI}/plugins/gridimporter/structured2dgridnaysgridimporter/languages/structured2dgridnaysgridimporter_id_ID.qm
  ${PREPOST_GUI}/plugins/gridimporter/structured2dgridnaysgridimporter/languages/structured2dgridnaysgridimporter_is_IS.qm
  ${PREPOST_GUI}/plugins/gridimporter/structured2dgridnaysgridimporter/languages/structured2dgridnaysgridimporter_it_IT.qm
  ${PREPOST_GUI}/plugins/gridimporter/structured2dgridnaysgridimporter/languages/structured2dgridnaysgridimporter_ja_JP.qm
  )
#install(FILES ${GRID_IMPORTER.structured2dgridnaysgrid}
#  DESTINATION ${CMAKE_INSTALL_PREFIX}/dev_src/packages/gridimporter_plugin.structured2dgridnaysgrid/data
#  )

# gridimporter_unstructured2dgridtriangleimporter
set(gridimporter_unstructured2dgridtriangleimporter
  ${PREPOST_GUI}/libdlls/Release/unstructured2dgridtriangleimporter.dll
  ${PREPOST_GUI}/plugins/gridimporter/unstructured2dgridtriangleimporter/languages/unstructured2dgridtriangleimporter_ar_EG.qm
  ${PREPOST_GUI}/plugins/gridimporter/unstructured2dgridtriangleimporter/languages/unstructured2dgridtriangleimporter_bg_BG.qm
  ${PREPOST_GUI}/plugins/gridimporter/unstructured2dgridtriangleimporter/languages/unstructured2dgridtriangleimporter_bs_BA.qm
  ${PREPOST_GUI}/plugins/gridimporter/unstructured2dgridtriangleimporter/languages/unstructured2dgridtriangleimporter_ca_ES.qm
  ${PREPOST_GUI}/plugins/gridimporter/unstructured2dgridtriangleimporter/languages/unstructured2dgridtriangleimporter_cs_CZ.qm
  ${PREPOST_GUI}/plugins/gridimporter/unstructured2dgridtriangleimporter/languages/unstructured2dgridtriangleimporter_da_DK.qm
  ${PREPOST_GUI}/plugins/gridimporter/unstructured2dgridtriangleimporter/languages/unstructured2dgridtriangleimporter_de_DE.qm
  ${PREPOST_GUI}/plugins/gridimporter/unstructured2dgridtriangleimporter/languages/unstructured2dgridtriangleimporter_el_GR.qm
  ${PREPOST_GUI}/plugins/gridimporter/unstructured2dgridtriangleimporter/languages/unstructured2dgridtriangleimporter_es_ES.qm
  ${PREPOST_GUI}/plugins/gridimporter/unstructured2dgridtriangleimporter/languages/unstructured2dgridtriangleimporter_et_EE.qm
  ${PREPOST_GUI}/plugins/gridimporter/unstructured2dgridtriangleimporter/languages/unstructured2dgridtriangleimporter_eu_ES.qm
  ${PREPOST_GUI}/plugins/gridimporter/unstructured2dgridtriangleimporter/languages/unstructured2dgridtriangleimporter_fi_FI.qm
  ${PREPOST_GUI}/plugins/gridimporter/unstructured2dgridtriangleimporter/languages/unstructured2dgridtriangleimporter_fr_FR.qm
  ${PREPOST_GUI}/plugins/gridimporter/unstructured2dgridtriangleimporter/languages/unstructured2dgridtriangleimporter_gl_ES.qm
  ${PREPOST_GUI}/plugins/gridimporter/unstructured2dgridtriangleimporter/languages/unstructured2dgridtriangleimporter_hi_IN.qm
  ${PREPOST_GUI}/plugins/gridimporter/unstructured2dgridtriangleimporter/languages/unstructured2dgridtriangleimporter_hu_HU.qm
  ${PREPOST_GUI}/plugins/gridimporter/unstructured2dgridtriangleimporter/languages/unstructured2dgridtriangleimporter_id_ID.qm
  ${PREPOST_GUI}/plugins/gridimporter/unstructured2dgridtriangleimporter/languages/unstructured2dgridtriangleimporter_is_IS.qm
  ${PREPOST_GUI}/plugins/gridimporter/unstructured2dgridtriangleimporter/languages/unstructured2dgridtriangleimporter_it_IT.qm
  ${PREPOST_GUI}/plugins/gridimporter/unstructured2dgridtriangleimporter/languages/unstructured2dgridtriangleimporter_ja_JP.qm
  )
#install(FILES ${GRID_IMPORTER.unstructured2dgridtriangle}
#  DESTINATION ${CMAKE_INSTALL_PREFIX}/dev_src/packages/gridimporter_plugin.unstructured2dgridtriangle/data
#  )


# IRIC_ICO
set(IRIC_ICO
  ${PREPOST_GUI}/apps/iricgui/images/iconiRICFile.ico
  )

# IRIC_EXE
set(IRIC_EXE
  ${PREPOST_GUI}/apps/iricgui/release/iRIC.exe
  )

# IRIC_DLLS
set(IRIC_DLLS
  ${PREPOST_GUI}/libdlls/Release/iricCs.dll
  ${PREPOST_GUI}/libdlls/Release/iricAxis2d.dll
  ${PREPOST_GUI}/libdlls/Release/iricAxis3d.dll
  ${PREPOST_GUI}/libdlls/Release/iricDistancemeasure.dll
  ${PREPOST_GUI}/libdlls/Release/iricMeasureddata.dll
  ${PREPOST_GUI}/libdlls/Release/iricGdNetcdf.dll
  ${PREPOST_GUI}/libdlls/Release/iricGdPoint.dll
  ${PREPOST_GUI}/libdlls/Release/iricGdPolyLine.dll
  ${PREPOST_GUI}/libdlls/Release/iricGdPointGroup.dll
  ${PREPOST_GUI}/libdlls/Release/iricGdPointmap.dll
  ${PREPOST_GUI}/libdlls/Release/iricGdPolydata.dll
  ${PREPOST_GUI}/libdlls/Release/iricGdPolydataGroup.dll
  ${PREPOST_GUI}/libdlls/Release/iricGdPolygon.dll
  ${PREPOST_GUI}/libdlls/Release/iricGdPolygonGroup.dll
  ${PREPOST_GUI}/libdlls/Release/iricGdPolyLine.dll
  ${PREPOST_GUI}/libdlls/Release/iricGdPolyLineGroup.dll
  ${PREPOST_GUI}/libdlls/Release/iricGdRiversurvey.dll
  ${PREPOST_GUI}/libdlls/Release/iricGeoio.dll
  ${PREPOST_GUI}/libdlls/Release/iricGccCenterandwidth.dll
  ${PREPOST_GUI}/libdlls/Release/iricGccCompoundchannel.dll
  ${PREPOST_GUI}/libdlls/Release/iricGccExternalprogram.dll
  ${PREPOST_GUI}/libdlls/Release/iricGccGridcombine.dll
  ${PREPOST_GUI}/libdlls/Release/iricGccGridgenerator.dll
  ${PREPOST_GUI}/libdlls/Release/iricGccLaplace.dll
  ${PREPOST_GUI}/libdlls/Release/iricGccPoisson.dll
  ${PREPOST_GUI}/libdlls/Release/iricGccRectangularregion.dll
  ${PREPOST_GUI}/libdlls/Release/iricGccRectangularregionlonlat.dll
  ${PREPOST_GUI}/libdlls/Release/iricGccRiversurvey.dll
  ${PREPOST_GUI}/libdlls/Release/iricGccRiversurvey15d.dll
  ${PREPOST_GUI}/libdlls/Release/iricGccTriangle.dll
  ${PREPOST_GUI}/libdlls/Release/iricGui.dll
  ${PREPOST_GUI}/libdlls/Release/iricGuibase.dll
  ${PREPOST_GUI}/libdlls/Release/iricGuicore.dll
  ${PREPOST_GUI}/libdlls/Release/iricHdRiversurveywaterelevation.dll
  ${PREPOST_GUI}/libdlls/Release/iricPython.dll
  ${PREPOST_GUI}/libdlls/Release/iricMisc.dll
  ${PREPOST_GUI}/libdlls/Release/iricGraph2d.dll
  ${PREPOST_GUI}/libdlls/Release/iricGraph2dhybrid.dll
  ${PREPOST_GUI}/libdlls/Release/iricGraph2dscattered.dll
  ${PREPOST_GUI}/libdlls/Release/iricGraph2dVerification.dll
  ${PREPOST_GUI}/libdlls/Release/iricPost2d.dll
  ${PREPOST_GUI}/libdlls/Release/iricPost2dbirdeye.dll
  ${PREPOST_GUI}/libdlls/Release/iricPost3d.dll
  ${PREPOST_GUI}/libdlls/Release/iricPostbase.dll
  ${PREPOST_GUI}/libdlls/Release/iricPre.dll
  ${PREPOST_GUI}/libdlls/Release/iricSolverconsole.dll
  ${PREPOST_GUI}/libdlls/Release/iricTmsLoader.dll
  ${PREPOST_GUI}/libdlls/Release/iricTriangle.dll
)

# iRIC_ES
# dev_src/packages/gui.prepost/data/languages/iRIC_es_ES.qm ???
# dev_src/packages/gui.prepost/data/languages/qt_es_ES.qm ???

# IRIC_JP
# dev_src/packages/gui.prepost/data/languages/iRIC_ja_JP.qm ???
# dev_src/packages/gui.prepost/data/languages/qtbase_ja_JP.qm ???
set(IRIC_JP
  ${PREPOST_GUI}/libs/dataitem/axis2d/languages/iricAxis2d_ja_JP.qm
  ${PREPOST_GUI}/libs/dataitem/axis3d/languages/iricAxis3d_ja_JP.qm
  ${PREPOST_GUI}/libs/cs/languages/iricCs_ja_JP.qm
  ${PREPOST_GUI}/libs/dataitem/distancemeasure/languages/iricDistancemeasure_ja_JP.qm
  ${PREPOST_GUI}/libs/gridcreatingcondition/centerandwidth/languages/iricGccCenterandwidth_ja_JP.qm
  ${PREPOST_GUI}/libs/gridcreatingcondition/compoundchannel/languages/iricGccCompoundchannel_ja_JP.qm
  ${PREPOST_GUI}/libs/gridcreatingcondition/externalprogram/languages/iricGccExternalprogram_ja_JP.qm
  ${PREPOST_GUI}/libs/gridcreatingcondition/gridcombine/languages/iricGccGridcombine_ja_JP.qm
  ${PREPOST_GUI}/libs/gridcreatingcondition/gridgenerator/languages/iricGccGridgenerator_ja_JP.qm
  ${PREPOST_GUI}/libs/gridcreatingcondition/laplace/languages/iricGccLaplace_ja_JP.qm
  ${PREPOST_GUI}/libs/gridcreatingcondition/poisson/languages/iricGccPoisson_ja_JP.qm
  ${PREPOST_GUI}/libs/gridcreatingcondition/rectangularregion/languages/iricGccRectangularregion_ja_JP.qm
  ${PREPOST_GUI}/libs/gridcreatingcondition/rectangularregionlonlat/languages/iricGccRectangularregionlonlat_ja_JP.qm
  ${PREPOST_GUI}/libs/gridcreatingcondition/riversurvey/languages/iricGccRiversurvey_ja_JP.qm
  ${PREPOST_GUI}/libs/gridcreatingcondition/riversurvey15d/languages/iricGccRiversurvey15d_ja_JP.qm
  ${PREPOST_GUI}/libs/gridcreatingcondition/triangle/languages/iricGccTriangle_ja_JP.qm
  ${PREPOST_GUI}/libs/geodata/netcdf/languages/iricGdNetcdf_ja_JP.qm
  ${PREPOST_GUI}/libs/geodata/pointmap/languages/iricGdPointmap_ja_JP.qm
  ${PREPOST_GUI}/libs/geodata/polygon/languages/iricGdPolygon_ja_JP.qm
  ${PREPOST_GUI}/libs/geodata/polygongroup/languages/iricGdPolygonGroup_ja_JP.qm
  ${PREPOST_GUI}/libs/geodata/polyline/languages/iricGdPolyLine_ja_JP.qm
  ${PREPOST_GUI}/libs/geodata/riversurvey/languages/iricGdRiversurvey_ja_JP.qm
  ${PREPOST_GUI}/libs/geoio/languages/iricGeoIO_ja_JP.qm
  ${PREPOST_GUI}/libs/post/graph2d/languages/iricGraph2d_ja_JP.qm
  ${PREPOST_GUI}/libs/post/graph2dhybrid/languages/iricGraph2dhybrid_ja_JP.qm
  ${PREPOST_GUI}/libs/post/graph2dscattered/languages/iricGraph2dscattered_ja_JP.qm
  ${PREPOST_GUI}/libs/post/graph2dverification/languages/iricGraph2dverification_ja_JP.qm
  ${PREPOST_GUI}/libs/gui/languages/iricGui_ja_JP.qm
  ${PREPOST_GUI}/libs/guibase/languages/iricGuibase_ja_JP.qm
  ${PREPOST_GUI}/libs/guicore/languages/iricGuicore_ja_JP.qm
  ${PREPOST_GUI}/libs/hydraulicdata/riversurveywaterelevation/languages/iricHdRiversurveywaterelevation_ja_JP.qm
  ${PREPOST_GUI}/libs/dataitem/measureddata/languages/iricMeasureddata_ja_JP.qm
  ${PREPOST_GUI}/libs/misc/languages/iricMisc_ja_JP.qm
  ${PREPOST_GUI}/libs/post/post2d/languages/iricPost2d_ja_JP.qm
  ${PREPOST_GUI}/libs/post/post2dbirdeye/languages/iricPost2dbirdeye_ja_JP.qm
  ${PREPOST_GUI}/libs/post/post3d/languages/iricPost3d_ja_JP.qm
  ${PREPOST_GUI}/libs/postbase/languages/iricPostbase_ja_JP.qm
  ${PREPOST_GUI}/libs/pre/languages/iricPre_ja_JP.qm
  ${PREPOST_GUI}/libs/solverconsole/languages/iricSolverconsole_ja_JP.qm
  ${PREPOST_GUI}/libs/gui/languages/qt_ja_JP.qm
  )

set(IRIC_CN
  ${PREPOST_GUI}/libs/dataitem/axis2d/languages/iricAxis2d_zh_CN.qm
  ${PREPOST_GUI}/libs/dataitem/axis3d/languages/iricAxis3d_zh_CN.qm
  ${PREPOST_GUI}/libs/cs/languages/iricCs_zh_CN.qm
  ${PREPOST_GUI}/libs/dataitem/distancemeasure/languages/iricDistancemeasure_zh_CN.qm
  ${PREPOST_GUI}/libs/gridcreatingcondition/centerandwidth/languages/iricGccCenterandwidth_zh_CN.qm
  ${PREPOST_GUI}/libs/gridcreatingcondition/compoundchannel/languages/iricGccCompoundchannel_zh_CN.qm
  ${PREPOST_GUI}/libs/gridcreatingcondition/externalprogram/languages/iricGccExternalprogram_zh_CN.qm
  ${PREPOST_GUI}/libs/gridcreatingcondition/gridcombine/languages/iricGccGridcombine_zh_CN.qm
  ${PREPOST_GUI}/libs/gridcreatingcondition/gridgenerator/languages/iricGccGridgenerator_zh_CN.qm
  ${PREPOST_GUI}/libs/gridcreatingcondition/laplace/languages/iricGccLaplace_zh_CN.qm
  ${PREPOST_GUI}/libs/gridcreatingcondition/poisson/languages/iricGccPoisson_zh_CN.qm
  ${PREPOST_GUI}/libs/gridcreatingcondition/rectangularregion/languages/iricGccRectangularregion_zh_CN.qm
  ${PREPOST_GUI}/libs/gridcreatingcondition/rectangularregionlonlat/languages/iricGccRectangularregionlonlat_zh_CN.qm
  ${PREPOST_GUI}/libs/gridcreatingcondition/riversurvey/languages/iricGccRiversurvey_zh_CN.qm
  ${PREPOST_GUI}/libs/gridcreatingcondition/riversurvey15d/languages/iricGccRiversurvey15d_zh_CN.qm
  ${PREPOST_GUI}/libs/gridcreatingcondition/triangle/languages/iricGccTriangle_zh_CN.qm
  ${PREPOST_GUI}/libs/geodata/netcdf/languages/iricGdNetcdf_zh_CN.qm
  ${PREPOST_GUI}/libs/geodata/pointmap/languages/iricGdPointmap_zh_CN.qm
  ${PREPOST_GUI}/libs/geodata/polygon/languages/iricGdPolygon_zh_CN.qm
  ${PREPOST_GUI}/libs/geodata/polygongroup/languages/iricGdPolygonGroup_zh_CN.qm
  ${PREPOST_GUI}/libs/geodata/polyline/languages/iricGdPolyLine_zh_CN.qm
  ${PREPOST_GUI}/libs/geodata/riversurvey/languages/iricGdRiversurvey_zh_CN.qm
  ${PREPOST_GUI}/libs/geoio/languages/iricGeoIO_zh_CN.qm
  ${PREPOST_GUI}/libs/post/graph2d/languages/iricGraph2d_zh_CN.qm
  ${PREPOST_GUI}/libs/post/graph2dhybrid/languages/iricGraph2dhybrid_zh_CN.qm
  ${PREPOST_GUI}/libs/post/graph2dscattered/languages/iricGraph2dscattered_zh_CN.qm
  ${PREPOST_GUI}/libs/post/graph2dverification/languages/iricGraph2dverification_zh_CN.qm
  ${PREPOST_GUI}/libs/gui/languages/iricGui_zh_CN.qm
  ${PREPOST_GUI}/libs/guibase/languages/iricGuibase_zh_CN.qm
  ${PREPOST_GUI}/libs/guicore/languages/iricGuicore_zh_CN.qm
  ${PREPOST_GUI}/libs/hydraulicdata/riversurveywaterelevation/languages/iricHdRiversurveywaterelevation_zh_CN.qm
  ${PREPOST_GUI}/libs/dataitem/measureddata/languages/iricMeasureddata_zh_CN.qm
  ${PREPOST_GUI}/libs/misc/languages/iricMisc_zh_CN.qm
  ${PREPOST_GUI}/libs/post/post2d/languages/iricPost2d_zh_CN.qm
  ${PREPOST_GUI}/libs/post/post2dbirdeye/languages/iricPost2dbirdeye_zh_CN.qm
  ${PREPOST_GUI}/libs/post/post3d/languages/iricPost3d_zh_CN.qm
  ${PREPOST_GUI}/libs/postbase/languages/iricPostbase_zh_CN.qm
  ${PREPOST_GUI}/libs/pre/languages/iricPre_zh_CN.qm
  ${PREPOST_GUI}/libs/solverconsole/languages/iricSolverconsole_zh_CN.qm
  ${PREPOST_GUI}/libs/gui/languages/qt_zh_CN.qm
  )

# IRIC_PY
set(IRIC_PY
  ${PREPOST_GUI}/apps/iricpython/iric.py
  )

# Install IRIC  
install(FILES ${IRIC_ICO} ${IRIC_EXE} ${IRIC_DLLS}
  DESTINATION ${CMAKE_INSTALL_PREFIX}/${SRC_FOLDER}/packages/gui.prepost/data
  )
install(FILES ${IRIC_JP}
  DESTINATION ${CMAKE_INSTALL_PREFIX}/${SRC_FOLDER}/packages/gui.prepost/data/languages
  )
install(FILES ${IRIC_CN}
  DESTINATION ${CMAKE_INSTALL_PREFIX}/${SRC_FOLDER}/packages/gui.prepost/data/languages
  )
install(FILES ${IRIC_PY}
  DESTINATION ${CMAKE_INSTALL_PREFIX}/${SRC_FOLDER}/packages/gui.runtime/data/pythonmodule
)

# Install RIVMAKER  
#install(FILES ${RIVMAKER_ICO} ${RIVMAKER_EXE} ${RIVMAKER_DLLS}
#  DESTINATION ${CMAKE_INSTALL_PREFIX}/dev_src/packages/gui.rivmaker/data
#  )
#install(FILES ${RIVMAKER_JP}
#  DESTINATION ${CMAKE_INSTALL_PREFIX}/dev_src/packages/gui.rivmaker/data/languages
#  )
