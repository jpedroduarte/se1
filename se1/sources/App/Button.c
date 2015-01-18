/** @file Button.c
*  Button module.
*/
#include "/home/user/Desktop/host-se1/se1/includes/Button.h"
#include "/home/user/Desktop/host-se1/se1/includes/Timer.h"

/**
 * Cria um novo botao atribuido a um pin
 * @param pinId Indica o pin a qual o botao esta ligado
 * @return retorna um novo botao
 */
Button Button_Init(int pinId){
	Button b = {0};
	b.pinMask = 1<<pinId;
	b.currentState = released;
	GPIO_config( 0, b.pinMask , 0 );
	return b;
}
/**
 * Devolve o valor que se encontra no pin daquele botao
 * @param b Butao da qual se pretende saber o estado do porto
 * @return retorna 0 ou 1
 */
int Button_getPortState(int maskButtons){
	return GPIO_input() & maskButtons;
}

/**
 * Avalia e altera o estado do botao
 * @param b Butao da qual se pretende avaliar o estado
 */
void Button_setState(Button *b){
	int state = Button_getPortState(b->pinMask);
	
	if(state == 0){
		if(b->currentState == pressed){
			b->currentState = just_released;
		}
		else if(b->currentState == just_released){
			b->currentState = released;
		}
		else if(b->currentState == just_pressed){
			b->currentState = just_released;
		}
		else{
			b->currentState = released;
		}
	}
	
	else{
		if(b->currentState == released){
			b->currentState = just_pressed;
		}
		else if(b->currentState == just_pressed){
			b->currentState = pressed;
		}
		else if(b->currentState == just_released){
			b->currentState = just_pressed;
		}
		else{
			b->currentState = pressed;
		}
	}

}

/**
 * Devolve 1 se o botao foi pressionado
 * @param b Arrray com os Botoes que se pretende verificar se foram pressionados
 * @param s Botao da qual se pretende avaliar o estado
 * @return retorna 0 ou 1
 */
void Button_getState(Button *b, int nBut){
	int i;
	for(i=0 ; i < nBut ; ++i){
		
		Button_setState(b);
		b++;
	}
}

/**
 * Devolve 1 se o botao foi pressionado
 * @param b Botao da qual se pretende avaliar o estado
 * @param t tempo para o botao estar pressionado
 * @return retorna 0 ou 1
 */
int Button_PressedMoreThan(Button b[], int t, int nBut){
	int mask = 0;
	int i;
	for( i = 0 ; i < nBut; ++i){
		mask |= b[i].pinMask;
	}
	unsigned now, ticks ;
	for(now = TMR0_GetValue() ; ((Button_getPortState(mask)) == mask) ;){
		ticks = (TicksToMS(TMR0_Elapsed(now)));
		if(ticks >= t)
			return 1;
	} 
	return 0;
}

