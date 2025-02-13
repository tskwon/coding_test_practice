function rotateArray(query, matrix) {
  //set clockwise 약
  let dx = [0, 1, 0, -1];
  let dy = [1, 0, -1, 0];

  let x = query[0] - 1;
  let y = query[1] - 1;

  let currNum = matrix[x][y];
  let minVal = currNum;

  let dir = 0;
  while (dir < 4) {
    let nx = x + dx[dir];
    let ny = y + dy[dir];

    if (nx < query[0] - 1 || nx > query[2] - 1 || ny < query[1] - 1 || ny > query[3] - 1) {
      dir++;
      continue;
    }

    let temp = matrix[nx][ny];
    matrix[nx][ny] = currNum;
    currNum = temp;
    x = nx;
    y = ny;
    minVal = Math.min(minVal, temp);
  }
  return minVal;
}

function solution(rows, columns, queries) {
  let answer = [];
  let matrix = Array.from({ length: rows }, (_, i) =>
    Array.from({ length: columns }, (_, j) => j + 1 + i * columns)
  );

  queries.forEach(query => {
    let minValue = rotateArray(query, matrix);
    answer.push(minValue);
  });

  return answer;
}
