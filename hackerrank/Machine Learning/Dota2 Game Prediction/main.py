# Author: wangyongliang.wyl@gmail.com (Wang Yongliang)
# github: https://github.com/wangyongliang
# Problem: https://www.hackerrank.com/challenges/dota2prediction (Dota 2 Game Prediction)
# Final score: 21.33
# Editor: predict via Bayes, suppose each hero is independten

import sys
from math import log
heros = dict()

with open('trainingdata.txt') as data:
  for line in data:
    terms = line.strip().split(',')
    win = terms[:5]
    lose = terms[5:-1]

    if terms[-1] =='2':
      lose,win = win,lose
    for x in win:
      heros[(x,1)] = heros.get((x,1), 1) + 1
    for x in lose:
      heros[(x,0)] = heros.get((x,0), 0) + 1

def calculate_hero_score(h):
  win = heros.get((h,1),0)
  lose = heros.get((h,0),0)
  return win * 1.0 / (win + lose)

def probo(team):
  scores = []
  for player in team:
    scores.append(calculate_hero_score(player))
  scores.sort()
  return scores

weight = [log(2) / log(7 - i) for i in range(1,6)]
# weight = [1.0 / (6 - i) for i in range(1,6)]

def calculate_team_score(scores):
  result = 1.0
  for x in scores:
    result = result * x
  return result

def dcg(scores):
  result = 0.0
  for x, y in zip(scores, weight):
    result += x * y
  return result

n = int(raw_input())
thredshold = 1.0
correct = 0
for i in range(0,n):
  line = raw_input().strip()
  terms = line.split(',')
  expect = int(terms[10])
  terms = terms[:10]
  left = probo(terms[:5])
  right = probo(terms[5:])

  # score = (calculate_team_score(left) + dcg(left) + sum(left) * 2) / (calculate_team_score(right) + dcg(right) + sum(right) * 2)
  score = (calculate_team_score(left) + dcg(left) + sum(left) * 2) / (calculate_team_score(right) + dcg(right) + sum(right) * 2)
  # score = dcg(left) / dcg(right)
  # score = left[4] / right[4]
  result = 0
  if score > thredshold:
    result = 1
  else:
    result = 2
  if result != expect:
    print '-'*100
    print left, sum(left)
    print right, sum(right)
    print score, expect
  else:
    correct += 1

print 'Correct: %d' % correct
print 'Total score: %lf' % ((correct * 2.0 - n) * 100 / n)
