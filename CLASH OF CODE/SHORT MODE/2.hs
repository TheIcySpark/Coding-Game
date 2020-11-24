import Data.Char
contarCiruclos d|d==0||d==6||d==9=1|d==8=2|otherwise=0
main = do
    s<-getLine
    print(foldl(\a x->a+contarCiruclos(ord x-ord '0'))0 s)