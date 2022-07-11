#include "Logo.h"
#include "SceneManager.h"
#include "InputManager.h"

#include "ObjectManager.h"
#include "Player.h"
#include "Enemy.h"
#include "Bullet.h"

#include "ObjectFactory.h"
#include"CursorManager.h"

Logo::Logo() { }
Logo::~Logo() { }

void Logo::Initialize()
{
	ObjectManager::GetInstance()->AddObject(ObjectFactory<Player>::CreateObject());
	SceneManager::GetInstance()->SetScene(SCENEID::STAGE);
}

void Logo::Update()
{
	DWORD dwKey = InputManager::GetInstance()->GetKey();

	if (dwKey & KEY_ENTER)
	{
		SceneManager::GetInstance()->SetScene(MENU);
	}
}

void Logo::Render()
{

}

void Logo::Release()
{
}
/*
     #			      #####           #			              ####### 
  # #		         #         #          #			#           #       
 #  #		         #         #          #			#           #       
     #			     ######          #			#	         #######  
     #			       	         #         #######                       #
     #			      #        #     				    #		     #            # 
 #####           ####		 		        #			  ######  
                               
*/

/*
¡û
¡¾
  */