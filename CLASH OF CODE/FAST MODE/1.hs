--Mostrar si los digitos de un numero son acendentes
main = do
    input_line <- getLine
    putStrLn(if foldl (\a (x,y) -> if y>=x then a else False ) True $ zip input_line (tail input_line) then
        "true" else "false")    
    return ()