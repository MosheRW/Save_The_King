target_include_directories (${CMAKE_PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_LIST_DIR})

target_sources (${CMAKE_PROJECT_NAME} PRIVATE 	"Moveable.h"
												"KingB.h"
												"MageB.h"
												"WarriorB.h"
												"ThiefB.h"
												"DwarfB.h")