import pandas as pd

def find_valid_emails(users: pd.DataFrame) -> pd.DataFrame:
    return users[users['email'].str.match(r'^[a-zA-Z0-9_]+@[a-zA-Z]+\.com$')].sort_values(by='user_id')
    