import Data.Char
main = do
    l <- getLine
    print(sum[ord x - ord '0'| x<- l]^2)