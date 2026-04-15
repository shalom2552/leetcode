import pandas as pd

def find_products(products: pd.DataFrame) -> pd.DataFrame:
    low_fat = products[products["low_fats"] == "Y"]
    low_rec = low_fat[low_fat["recyclable"] == "Y"]
    return low_rec[["product_id"]]