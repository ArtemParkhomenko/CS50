from cs50 import SQL
from flask import request
from helpers import lookup

db = SQL("sqlite:///finance.db")

def getCash(id):
    # Get cash from data base
    return db.execute('SELECT cash FROM users WHERE id = :id', id=id)[0]['cash']
    
def addTransaction(id, symbol, name, shares, price, cash):
        
        # Add transaction in data base
        sqlCommand = """INSERT INTO transactions (user_id, symbol, name, shares, price) 
            VALUES (:user_id, :symbol, :name, :shares, :price)"""
        db.execute(sqlCommand, user_id = id, symbol = symbol, name = name, shares = shares, price = price)
        
        # Update user cash
        db.execute("UPDATE users SET cash = :cash WHERE id = :id", cash = cash, id = id)
        
def parseTransactions(id):
    
    # Get rows transactions from data base
    rows = db.execute('SELECT symbol, name, shares FROM transactions WHERE user_id = :id', id=id)
    
    # Create list
    userShares = []
    
    # Go by rows, and add data to our list
    for row in rows:
        for temp in userShares:
            if temp['symbol'] == row['symbol']:
                temp['shares'] += row['shares']
                break
        else:
            userShares.append({'symbol': row['symbol'], 'name': row['name'], 'shares': row['shares']})
    
    # Write total in userShares
    for temp in userShares:
        data = lookup(temp['symbol'])
        temp['price'] = data['price']
        temp['total'] = temp['price'] * temp['shares']
        
    return list(filter(lambda x: x['total'], userShares))

def getTotal(cash, userShares):
    
    total = 0
    
    for temp in userShares:
        total += temp['total']
        
    return total+cash
    
def getShares(id, symbol):
    return db.execute("SELECT SUM(shares) FROM transactions WHERE user_id=:id AND symbol=:symbol" , id=id, symbol=symbol)[0]['SUM(shares)']

def getUser(id):
    return db.execute("SELECT * FROM users WHERE id = :id", id=id)
    