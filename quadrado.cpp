#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdio.h>
#define TAMANHO_JANELA 500

float gX = 0.0, mouseX = 0;
float gY = 0.0, mouseY = 0;
int keyStatus[256] = {0};
int rightButtonIsPressed = 0, isDragging = 0;

/*void idle(void){
    glutPostRedisplay();
}*/

//Move o quadrado de acordo com o click do mouse
void move(int x, int y){
   if(rightButtonIsPressed){
      isDragging = 1;
      y = TAMANHO_JANELA - y;
      gX = (float) x/TAMANHO_JANELA;
      gY = (float) y/TAMANHO_JANELA;
      //printf("x: %d  y: %d\n", x, y);
      glutPostRedisplay();
   }
}

// Trata os eventos de click de mouse
void mouse(int button, int state, int x, int y){
   if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN){
      //printf("clicou\n");
      rightButtonIsPressed = 1;
      
   }
   if(button == GLUT_LEFT_BUTTON && state == GLUT_UP){
     // printf("soltou\n");
      rightButtonIsPressed = 0;
   }
   
}
 //Clicar a tecla e segurar, realizar o movimento enquanto a tecla está pressionada
void idle(void){
   if(keyStatus[(int)('a')] == 1){
      gX= gX-0.001;
   }
   if(keyStatus[(int)('s')] == 1){
      gY = gY-0.001;
   }
   if(keyStatus[(int)('d')] == 1){
     gX= gX+0.001;
   }
   if(keyStatus[(int)('w')] == 1){
      gY = gY+0.001;
   }
   glutPostRedisplay();
}

void keyUp(unsigned char key, int x, int y){
   keyStatus[(int)(key)] = 0;
}

void keyPress(unsigned char key, int x, int y){
   keyStatus[(int)(key)] =1;
}


/*//Realiza 1 movimento por vez
void keyPress(unsigned char key, int x, int y){ 
   if(key == 'a'){
      gX= gX-0.01;
   }
   if(key == 's'){
      gY = gY-0.01;
   }
   if(key == 'd'){
      gX = gX+0.01;
   }
   if(key == 'w'){
      gY = gY+0.01;    
   }
   
   glutPostRedisplay();
}*/

void display(void){
   /* Limpar todos os pixels  */
   glClear (GL_COLOR_BUFFER_BIT);

   /* Define cor dos vértices com os valores R, G e B variando de 0.0 a 1.0 */
   glColor3f (1.0, 1.0, 1.0);
   /* Desenhar um polígono branco (retângulo) */
   glBegin(GL_POLYGON);

      /*glVertex3f (0.25+gX, 0.25+gY, 0.0); // inf esq
      glVertex3f (0.75+gX, 0.25+gY, 0.0); // sup esq
      glVertex3f (0.75+gX, 0.75+gY, 0.0); // sup dir
      glVertex3f (0.25+gX, 0.75+gY, 0.0); // inf dir
      */
      
      // Colocando a origem mais próxima do click do mouse
      glVertex3f (-0.20+gX, -0.20+gY, 0.0); // inf esq
      glVertex3f (0.2+gX, -0.20+gY, 0.0); // sup esq
      glVertex3f (0.2+gX, 0.2+gY, 0.0); // sup dir
      glVertex3f (-0.20+gX, 0.2+gY, 0.0); // inf dir

   
   glEnd();

   /* Desenhar no frame buffer! */
   glutSwapBuffers(); //Funcao apropriada para janela double buffer
}

void init (void) {
  /* selecionar cor de fundo (preto) */
  glClearColor (0.0, 0.0, 0.0, 0.0);

  /* inicializar sistema de visualizacao */
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
}

int main(int argc, char** argv){
   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
   glutInitWindowSize (TAMANHO_JANELA, TAMANHO_JANELA); 
   glutInitWindowPosition (100, 100);
   glutCreateWindow ("hello world");
   init();
   glutDisplayFunc(display); 

   glutKeyboardFunc(keyPress);

   glutKeyboardUpFunc(keyUp);
   //glutIdleFunc(idle);

   glutMouseFunc(mouse);
   glutMotionFunc(move);
      
   glutMainLoop();

   return 0;
}
