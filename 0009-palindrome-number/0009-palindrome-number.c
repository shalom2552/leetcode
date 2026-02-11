bool isPalindrome(int x) {

    // negative number is not a palindrome
    if (x < 0) {
        return false;
    } 
    // one digit number is always a palindrome
    if (x < 10){
        return true;
    }

    // find 10 multiplayer
    int d = 1;
    while (10 <= x / d) {
        d *= 10;
    }
    
    int l = 0;
    int r = 0;
    while (x > 0) {
        // update indicis
        r = x % 10;
        l = x / d;
        
        // not a palindrome
        if (l != r) {
            return false;
        }

        // trim left and right
        x = x % d;
        x = x / 10;
        d /= 100;
    }

    return true;
}