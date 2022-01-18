target_include_directories (${CMAKE_PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_LIST_DIR})

target_sources (${CMAKE_PROJECT_NAME} PRIVATE "Button.h"
												"classes.h"
												"Globals.h"
												"HelpMenu.h"
												"Location.h"
												"Organ.h"
												"Square.h"
												"TopBar.h")
