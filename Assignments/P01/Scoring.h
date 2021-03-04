#pragma once


class Scoring
{
    private:
        int score;
    
    public:
        Scoring()               // default constructor for Scoring
        {
            score = 0;          // Score always starts with 0
        }                       // that's why no non-def constr.


        /**
         * Description:
         *      Adds 1 to member variable "score"
         * Params:
         *      No params
         * 
         * Returns:
         *      Void, no return
         */
        void plusScore()
        {
            score++;
        }

        /**
         * Description:
         *      Subtracts 1 from member variable "score"
         * Params:
         *      No params
         * 
         * Returns:
         *      Void, no return
         */
        void minusScore()
        {
            score--;
        }

        /**
         * Description:
         *      Returns "score". Basic OOP get-method
         * Params:
         *      No params
         * 
         * Returns:
         *      Int, returns score
         */
        int getScore()
        {
            return score;
        }
};
