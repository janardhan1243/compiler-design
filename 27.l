Algorithm CountVowelsAndConsonants(sentence):
    // Initialize counters
    vowelCount = 0
    consonantCount = 0

    // Define a function to check if a character is a vowel
    Function IsVowel(char):
        return char is one of {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'}

    // Iterate through each character in the sentence
    For each char in sentence:
        // Check if the character is an alphabet letter
        If char is an alphabet letter:
            // Check if the character is a vowel
            If IsVowel(char):
                // Increment vowel count
                vowelCount = vowelCount + 1
            Else:
                // Increment consonant count
                consonantCount = consonantCount + 1

    // Output the results
    Print "Number of vowels: ", vowelCount
    Print "Number of consonants: ", consonantCount
End Algorithm
