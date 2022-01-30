import java.util.Scanner;
import java.util.Random;

class TicTacToeBoard {

    public static void main(String[] args){

        Scanner scanner = new Scanner(System.in);
        Random random = new Random();
        //x p1
        //o p2
        System.out.print("What is your name? ");
        String p1 = scanner.nextLine();
        String p2 = "Computer";
        System.out.println("You will be playing against the " +p2);
        
        char Board[][] = new char[3][3];

        for(int i = 0; i < 3; i++){

            for(int j = 0; j < 3; j++){
                Board[i][j] = '-';
            }

        }

        boolean isPlayer1 = true;
        boolean gameEnd = false;
        int x = random.nextInt(1); //random assignment either 0 or 1 
        

    while(!gameEnd)
 {

        drawBoard(Board);

        char symbol = ' ';

        if(x == 1 && isPlayer1) {
            symbol ='x';
        }
        else{
            symbol = 'o';
        }

            if(x == 1 && isPlayer1){
                System.out.println(p1 + "'s Turn : " +symbol );
            }
            else{
                System.out.println(p2 + "'s Turn : " +symbol );
            }


        if (x == 0){             // when x = 1 never changes 
            isPlayer1 = false;
        }
    
        int row = 0; 
        int col = 0; 

        while(!gameEnd) {
            if ( x == 1 && isPlayer1 ){                //if x = 1 ask player where to put r x c
            System.out.print("Enter row (0,1,2): ");
            row = scanner.nextInt();
            
            System.out.print("Enter col (0,1,2): ");
            col = scanner.nextInt();
            }

            else if (isPlayer1 == false){                     //if x = 0 randomly place where to put r x c
                row = random.nextInt(3);
                col = random.nextInt(3);
            }
            
            if(row < 0 || col < 0 || col > 2 || row > 2){
                System.out.println("Illegal move ! ");
            }
            else if(Board[row][col] != '-'){
                System.out.println("Cell not empty ! ");
            }
            else{
                break;
            }
            
        }

        Board[row][col] = symbol;

        if(Won(Board) == 'x'){
            System.out.println(p1 + " has won!");
            gameEnd = true;
        }
        else if(Won(Board) == 'o'){
            System.out.println(p2 + " has won!");
            gameEnd = true;
        }
        else{
            if(Tie(Board)){
                System.out.println("Tie game! Thank you for playing!");
                gameEnd = true;
            }
            else{
                // not a tie & game has not ended assign !p1 to p1 then re-loop 
                isPlayer1 = !isPlayer1;
                 if (x == 0) {
                     x = 1;
                 }
                }
                
            }

     }
            
            drawBoard(Board);
            scanner.close();

    }

   
    public static void drawBoard(char[][] Board) {
    for(int i = 0; i < 3; i++){

        for(int j = 0; j < 3; j++){
            System.out.print(Board[i][j]);
        }
        System.out.println();
    }  
    }

    public static char Won(char[][] Board) {
        for(int i = 0; i < 3; i++){
    
            if(Board[i][0] == Board[i][1] && Board[i][1] == Board[i][2] &&
            Board[i][0] != '-'){
                return Board[i][0];
            }
        }  
    
        for(int j = 0; j < 3; j++){
        
            if(Board[0][j] == Board[1][j] && Board[1][j] == Board[2][j] &&
            Board[0][j] != '-'){
                return Board[0][j];
            }
        }  
        
        if(Board[0][0] == Board[1][1] && Board[1][1] == Board[2][2] && Board[0][0] != '-'){
            return Board[0][0];
        }
        if(Board[2][0] == Board[1][1] && Board[1][1] == Board[0][2] && Board[2][2] != '-'){
            return Board[2][0];
        }

        return '-';

    }        

    public static boolean Tie(char[][] Board) {
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                if(Board[i][j] == '-'){
                    return false;
                }
            }
        }
        return true;
    }

   
}