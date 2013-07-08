# Author: wangyongliang.wyl@gmail.com (Wang Yongliang)
# github: https://github.com/wangyongliang
# Problem: https://www.hackerrank.com/challenges/dota2prediction (Dota 2 Game Prediction)
# Final score: 21.33
# Editor: predict via Bayes, suppose each hero is independten

import sys
heros = dict()

with open('trainingdata.txt') as data:
  for line in data:
    terms = line.strip().split(',')
    win = terms[:5]
    lose = terms[5:-1]
    
    if terms[-1] =='2': 
      lose,win = win,lose     
    for x in win:
      heros[(x,1)] = heros.get((x,1),0) + 1     
    for x in lose:
      heros[(x,0)] = heros.get((x,0),0) + 1

def calculate_hero_score(h):
  win = heros.get((h,1),0)
  lose = heros.get((h,0),0)
  return win * 1.0 / (win + lose)

def calculate_team_score(team):
  result = 1.0
  for x in team:    
    result = result * calculate_hero_score(x)
  return result

n = int(raw_input())
for i in range(0,n):
  line = raw_input().strip()
  terms = line.split(',')
  left = terms[:5]
  right = terms[5:]
  if calculate_team_score(left) > calculate_team_score(right):
    print '1'
  else:
    print '2'
