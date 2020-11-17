import System.IO ()
import Control.Monad 
import Data.List

obtenerMenorDiferencia entrada = 
    minimum $ map (\(x,y) -> abs $ x - y) (zip ordenado $ tail ordenado)
    where
        ordenado = sort $ map(\x -> read x:: Int) entrada

main :: IO()
main = do
    linea_entrada <- getLine
    let n = read linea_entrada :: Int

    lineas <- replicateM n getLine        

    print(obtenerMenorDiferencia lineas)

    return()