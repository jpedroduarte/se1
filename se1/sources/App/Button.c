/** @file Button.c
*  Button module.
*/
#include "/home/user/Desktop/host-se1/se1/includes/Button.h"

/**
 * Define os tipos de estados que um botao pode ter
 */
enum states {just_pressed, pressed, just_released, released};

/**
 * Cria um novo botao atribuido a um pin
 * @param pinId Indica o pin a qual o botao esta ligado
 * @return retorna um novo botao
 */
Button Button_Init(int pinId){
	Button b = {0};
	b.pinMask = 1<<pinId;
	GPIO_config( 0, b.pinMask , 0 );
	return b;
}
/**
 * Devolve o valor que se encontra no pin daquele botao
 * @param b Butao da qual se pretende saber o estado do porto
 * @return retorna 0 ou 1
 */
int Button_getPortState(Button b){
	return GPIO_input() & b.pinMask;
}

/**
 * Avalia e altera o estado do botao
 * @param b Butao da qual se pretende avaliar o estado
 */
void Button_setState(Button b){
	int state = Button_getPortState(b);
	
	if(state == 0){
		if(b.currentState == pressed){
			b.currentState = just_released;
			break;
		}
		if(b.currentState == just_released){
			b.currentState = released;
			break;
		}
		if(b.currentState == just_pressed){
			b.currentState = just_released;
			break;
		}
		else{
			b.currentState = released;
			break;
		}
	}
	
	if(state == 1){
		if(b.currentState == released){
			b.currentState = just_pressed;
			break;
		}
		if(b.currentState == just_pressed){
			b.currentState = pressed;
			break;
		}
		if(b.currentState == just_released){
			b.currentState = just_pressed;
			break;
		}
		else{
			b.currentState = pressed;
			break;
		}
	}

}
