isBalanced:: String -> String -> Bool
isBalanced [] [] = True
isBalanced [] _ = False
isBalanced (x:xs) p
    |elem x "{([" = isBalanced xs (p++[x])
    |not (elem x ")}]") = isBalanced xs p
    |p /= [] && ((x == ')' && last p == '(') || (x == ']' && last p == '[') || (x == '}' && last p == '{'))
        = isBalanced xs (init p)
    |otherwise = False

main = do
    input_line <- getLine
    let e = input_line :: String
    putStrLn(if isBalanced e [] then "true" else "false")

    return ()